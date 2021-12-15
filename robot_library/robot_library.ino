/*
 * Function list
 * 
 * setAccel(int);
 * set acceleration for all motors
 * 
 * moveSteps(int);
 * mvoe x steps
 * 
 * moveMM(int);
 * move x millimeters
 * 
 * runMotors();
 * run commands for all motors
 */

void loop() {
  setAccel(5000);
  moveMM(20);
  
  runMotors();
}
