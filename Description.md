# ArduinoObjectCollision
Works like a state machine, where state 0 picks a new case, state one turns the lights on, state two turn the lights off, and uses the LEDCONTROL.H library to turn lights on and off. The currentStep integer increases each times void loop() function and it gets resets to 0 when it hits eight and the state changes. Once criteria is hit, a new case is generated.
The Delay Function is removed to avoid freezing the program, millis is used and counted using the external crystal oscillater.
An LCD screen is used and an Object Collision function is implemented to increase the score.
