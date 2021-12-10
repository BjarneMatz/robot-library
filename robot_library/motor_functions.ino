//librarys
#include <AccelStepper.h>
#include <MultiStepper.h>


//#############
//calculations
//#############

float wheel = diameter * 3.141592; //circumference of wheel in mm
float meter = steps / wheel * 1000; //1 meter = 'meter' steps
float maxms = maxkmh / 3.6; //km/h -> m/s
int maxspeed = maxms * meter; //m/s -> steps/s



//############################
//define pinout of all motors
//############################

//motorinterface master master
#define motorInterfaceType 1

//stepper motor front left
#define dirPinFL 2
#define stepPinFL 3

//stepper motor front right
#define dirPinFR 4
#define stepPinFR 5

//stepper motor rear left
#define dirPinRL 6
#define stepPinRL 7

//stepper motor rear right
#define dirPinRR 10
#define stepPinRR 11

//assign motors to variables
AccelStepper smFL = AccelStepper(motorInterfaceType, stepPinFL, dirPinFL);
AccelStepper smFR = AccelStepper(motorInterfaceType, stepPinFR, dirPinFR);
AccelStepper smRL = AccelStepper(motorInterfaceType, stepPinRL, dirPinRL);
AccelStepper smRR = AccelStepper(motorInterfaceType, stepPinRR, dirPinRR);

void setup() {
  Serial.begin(9600);
  Serial.println("Motor Data:");
  Serial.print("Steps per Revolution: ");
  Serial.println(steps);
  Serial.print("Steps per Meter: ");
  Serial.println(meter);
  Serial.print("Steps: ");
  Serial.println(maxspeed);

  
  //set max speed according to calculations
  smFL.setMaxSpeed(maxspeed);
  smFR.setMaxSpeed(maxspeed);
  smRL.setMaxSpeed(maxspeed);
  smRR.setMaxSpeed(maxspeed);
  Serial.println("set max speed...");
}


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


void moveMM(int i){
  float e = meter / 1000 * i;
  smFL.moveTo(e);
  smFR.moveTo(e);
  smRL.moveTo(e);
  smRR.moveTo(e);
}
