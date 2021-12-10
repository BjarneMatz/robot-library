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
#define dirPinRR 8
#define stepPinRR 9

//assign motors to variables
AccelStepper smFL = AccelStepper(motorInterfaceType, stepPinFL, dirPinFL);
AccelStepper smFR = AccelStepper(motorInterfaceType, stepPinFR, dirPinFR);
AccelStepper smRL = AccelStepper(motorInterfaceType, stepPinRL, dirPinRL);
AccelStepper smRR = AccelStepper(motorInterfaceType, stepPinRR, dirPinRR);
