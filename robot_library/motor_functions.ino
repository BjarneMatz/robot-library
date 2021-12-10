void runMotors(){
  //run all motors with corresponding settings
  smFL.run();
  smFR.run();
  smRL.run();
  smRR.run();
}

void setAccel(int i){
  //set accelerations for motors
  smFL.setAcceleration(i);
  smFR.setAcceleration(i);
  smRL.setAcceleration(i);
  smRR.setAcceleration(i);
}

void moveSteps(int i){
  //move motors to specific point
  smFL.moveTo(i);
  smFR.moveTo(i);
  smRL.moveTo(i);
  smRR.moveTo(i);
}
