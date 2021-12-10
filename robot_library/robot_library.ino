/*
 * Function list
 * 
 * setAccel(int);
 * set acceleration for all motors
 * 
 * moveSteps(int);
 * mvoe x steps
 * 
 * runMotors();
 * run commands for all motors
 */

void loop() {
  serialCommand();
  setAccel(1000);
  moveMM(-10);
  
  runMotors();
}
