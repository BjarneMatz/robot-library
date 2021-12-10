


void setup() {
  //set max speed according to calculations
  smFL.setMaxSpeed(maxspeed);
  smFR.setMaxSpeed(maxspeed);
  smRL.setMaxSpeed(maxspeed);
  smRR.setMaxSpeed(maxspeed);
}

void loop() {
  setAccel(500);
  moveSteps(10000);
  runMotors();
}

void runMotors(){
  //run all motors with corresponding settings
  smFL.run();
  smFR.run();
  smRL.run();
  smRR.run();
}

void setAccel(int i){
  smFL.setAcceleration(i);
  smFR.setAcceleration(i);
  smRL.setAcceleration(i);
  smRR.setAcceleration(i);
}

void moveSteps(int i){
  smFL.moveTo(i);
  smFR.moveTo(i);
  smRL.moveTo(i);
  smRR.moveTo(i);
}
