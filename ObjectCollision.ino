#include "LedControl.h"
#include "Wire.h"
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);
LedControl lc = LedControl(12, 11, 10, 1);
#define PinX A0 //Vrx
#define PinY A1 //Vry
#define PinS 2  //SW
unsigned long previousMillis = 0;
unsigned long startTime;
const long interval = 25; //milliseconds that each pixel in "if-loop" is delayed
int currentState = 0;
int currentStep = 0;
int randomCase = 0;
int lastX = -1;
int lastY = -1;
int score = 0;
void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  randomSeed(analogRead(0));
  pinMode(PinS, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.clear();
  lcd.print("score = ");
  lcd.print(score);
  startTime = millis();
}
bool objectCollision(int row, int col, float x, float y) {
    return (col >= x && col <= x + 1) && (row >= y && row <= y + 1);
}
void loop() {
  if (millis() - startTime > 20000) {  // milliseconds for the duration of the program
      return;
  }
  float x, y;
  x = floor(analogRead(PinX) / (1023. / 7));
  y = floor(analogRead(PinY) / (1023. / 7));
  if (x > 6) { x = 6; }
  if (y > 6) { y = 6; }
  if (lastX != -1 && lastY != -1) {
    lc.setLed(0, lastY, lastX, false);
    lc.setLed(0, lastY, lastX + 1, false);
    lc.setLed(0, lastY + 1, lastX, false);
    lc.setLed(0, lastY + 1, lastX + 1, false);
  }
  lc.setLed(0, y, x, true);
  lc.setLed(0, y, x + 1, true);
  lc.setLed(0, y + 1, x, true);
  lc.setLed(0, y + 1, x + 1, true);
  lastX = x;
  lastY = y;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (currentState == 0) {
          randomCase = random(1, 33);
          currentState = 1;
          currentStep = 0;
      }
      switch (randomCase) {
          case 1:
              if (currentState == 1) {
                  lc.setLed(0, 0, currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(0, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 0, currentStep, false);
              }
              break;
          case 2:
              if (currentState == 1) {
                  lc.setLed(0, 1, currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(1, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 1, currentStep, false);
              }
              break;
          case 3:
              if (currentState == 1) {
                  lc.setLed(0, 2, currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(2, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 2, currentStep, false);
              }
              break;
          case 4:
              if (currentState == 1) {
                  lc.setLed(0, 3, currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(3, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 3, currentStep, false);
              }
              break;
          case 5:
              if (currentState == 1) {
                  lc.setLed(0, 4, currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(4, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 4, currentStep, false);
              }
              break;
          case 6:
              if (currentState == 1) {
                  lc.setLed(0, 5, currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(5, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 5, currentStep, false);
              }
              break;
          case 7:
              if (currentState == 1) {
                  lc.setLed(0, 6, currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(6, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 6, currentStep, false);
              }
              break;
          case 8:
              if (currentState == 1) {
                  lc.setLed(0, 7, currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(7, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 7, currentStep, false);
              }
              break;
          case 9:
              if (currentState == 1) {
                  lc.setLed(0, currentStep, 0, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 0, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, currentStep, 0, false);
              }
              break;
          case 10:
              if (currentState == 1) {
                  lc.setLed(0, currentStep, 1, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 1, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, currentStep, 1, false);
              }
              break;
          case 11:
              if (currentState == 1) {
                  lc.setLed(0, currentStep, 2, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 2, x, y)) {
                          score += 1;;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, currentStep, 2, false);
              }
              break;
          case 12:
              if (currentState == 1) {
                  lc.setLed(0, currentStep, 3, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 3, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, currentStep, 3, false);
              }
              break;
          case 13:
              if (currentState == 1) {
                  lc.setLed(0, currentStep, 4, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 4, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, currentStep, 4, false);
              }
              break;
          case 14:
              if (currentState == 1) {
                  lc.setLed(0, currentStep, 5, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 5, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, currentStep, 5, false);
              }
              break;
          case 15:
              if (currentState == 1) {
                  lc.setLed(0, currentStep, 6, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 6, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, currentStep, 6, false);
              }
              break;
          case 16:
              if (currentState == 1) {
                  lc.setLed(0, currentStep, 7, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 7, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, currentStep, 7, false);
              }
              break;
          case 17:
              if (currentState == 1) {
                  lc.setLed(0, 0, 7 - currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(0, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 0, 7 - currentStep, false);
              }
              break;
          case 18:
              if (currentState == 1) {
                  lc.setLed(0, 1, 7 - currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(1, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 1, 7 - currentStep, false);
              }
              break;
          case 19:
              if (currentState == 1) {
                  lc.setLed(0, 2, 7 - currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(2, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 2, 7 - currentStep, false);
              }
              break;
          case 20:
              if (currentState == 1) {
                  lc.setLed(0, 3, 7 - currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(3, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 3, 7 - currentStep, false);
              }
              break;
          case 21:
              if (currentState == 1) {
                  lc.setLed(0, 4, 7 - currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(4, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 4, 7 - currentStep, false);
              }
              break;
          case 22:
              if (currentState == 1) {
                  lc.setLed(0, 5, 7 - currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(5, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 5, 7 - currentStep, false);
              }
              break;
          case 23:
              if (currentState == 1) {
                  lc.setLed(0, 6, 7 - currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(6, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 6, 7 - currentStep, false);
              }
              break;
          case 24:
              if (currentState == 1) {
                  lc.setLed(0, 7, 7 - currentStep, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(7, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 7, 7 - currentStep, false);
              }
              break;
          case 25:
              if (currentState == 1) {
                  lc.setLed(0, 7 - currentStep, 0, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 0, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 7 - currentStep, 0, false);
              }
              break;
          case 26:
              if (currentState == 1) {
                  lc.setLed(0, 7 - currentStep, 1, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 1, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 7 - currentStep, 1, false);
              }
              break;
          case 27:
              if (currentState == 1) {
                  lc.setLed(0, 7 - currentStep, 2, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(0, i, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 7 - currentStep, 2, false);
              }
              break;
          case 28:
              if (currentState == 1) {
                  lc.setLed(0, 7 - currentStep, 3, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 3, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 7 - currentStep, 3, false);
              }
              break;
          case 29:
              if (currentState == 1) {
                  lc.setLed(0, 7 - currentStep, 4, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 4, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 7 - currentStep, 4, false);
              }
              break;
          case 30:
              if (currentState == 1) {
                  lc.setLed(0, 7 - currentStep, 5, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 5, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 7 - currentStep, 5, false);
              }
              break;
          case 31:
              if (currentState == 1) {
                  lc.setLed(0, 7 - currentStep, 6, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 6, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 7 - currentStep, 6, false);
              }
              break;
          case 32:
              if (currentState == 1) {
                  lc.setLed(0, 7 - currentStep, 7, true);
                  for (int i = 0; i < 8; i++) {
                      if (objectCollision(i, 7, x, y)) {
                          score += 1;
                          lcd.clear();
                          lcd.print("score = ");
                          lcd.print(score);
                          break;
                      }
                  }
              } else if (currentState == 2) {
                  lc.setLed(0, 7 - currentStep, 7, false);
              }
              break;
      }
      currentStep++;
      if (currentStep >= 8) {
          currentStep = 0;
          if (currentState == 1) {
              currentState = 2; // Switch to Turning off
          } else if (currentState == 2) {
              currentState = 0; // Reset and select a new random case
          }
      }
  }
}
