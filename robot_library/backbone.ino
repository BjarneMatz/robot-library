//librarys
#include <AccelStepper.h>
#include <MultiStepper.h>
#define NOTE_C6  1047
#define NOTE_C7  2093
//motor and wheel settings

//#############
//calculations
//#############
//roboter config
#define diameter 100 //set to mm of wheel diameter
#define steps 400 //set to steps per revolution
#define maxkmh 1 //set to max speed to drive in km/h

//calculate various speed units
float wheel = diameter * 3.141592; //circumference of wheel in mm
float meter = steps / wheel * 1000; //1 meter = 'meter' steps
float maxms = maxkmh / 3.6; //km/h -> m/s
int maxspeed = maxms * meter; //m/s -> steps/s


//############################
//define pinout of all motors
//############################

//motorinterface master
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
#define dirPinRR 11
#define stepPinRR 12

//assign motors to variables
AccelStepper smFL = AccelStepper(motorInterfaceType, stepPinFL, dirPinFL);
AccelStepper smFR = AccelStepper(motorInterfaceType, stepPinFR, dirPinFR);
AccelStepper smRL = AccelStepper(motorInterfaceType, stepPinRL, dirPinRL);
AccelStepper smRR = AccelStepper(motorInterfaceType, stepPinRR, dirPinRR);

//pinout off signal rgb led and speaker
#define RGBR 8
#define RGBG 9
#define RGBB 10

#define buzzer 22



void setup() {
  Serial.begin(9600);
  //clear console
  for(int i=0; i<10; i++){
    Serial.println("");
  }

  //initialize rgb pins
  pinMode(RGBR, OUTPUT);
  pinMode(RGBG, OUTPUT);
  pinMode(RGBB, OUTPUT);

  //run start sequence
  analogWrite(RGBR, 255);
  tone(buzzer, NOTE_C6, 100);
  delay(100);
  tone(buzzer, NOTE_C7, 100);
  Serial.println("booting...");
  delay(1000);


  //set max speed according to calculations
  smFL.setMaxSpeed(maxspeed);
  smFR.setMaxSpeed(maxspeed);
  smRL.setMaxSpeed(maxspeed);
  smRR.setMaxSpeed(maxspeed);
  Serial.println("set max speed...");
}


void runMotors() {
  //run all motors with corresponding settings
  smFL.run();
  smFR.run();
  smRL.run();
  smRR.run();
}

void setAccel(int i) {
  //set accelerations for motors
  smFL.setAcceleration(i);
  smFR.setAcceleration(i);
  smRL.setAcceleration(i);
  smRR.setAcceleration(i);
}

void moveSteps(int i) {
  //move motors to specific point
  smFL.moveTo(i);
  smFR.moveTo(i);
  smRL.moveTo(i);
  smRR.moveTo(i);
}
void rightturn(){
}


void moveMM(int i) {
  float e = meter / 1000 * i; //calculate steps out of supplied millimeters
  smFL.moveTo(e);
  smFR.moveTo(e);
  smRL.moveTo(e);
  smRR.moveTo(e);
}
