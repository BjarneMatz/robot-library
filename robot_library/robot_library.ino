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
  setAccel(1000);
  rightturn();
  
  runMotors();
}
