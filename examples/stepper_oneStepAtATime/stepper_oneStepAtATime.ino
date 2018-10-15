//**************************************************************************//
//*************************** Created by ***********************************//
//*********************** Author : Jay Dalwadi *****************************//
//******** Github Link: https://github.com/jaydalwadi01/MyStepper **********//
//************************** Example Code **********************************//
//**************************************************************************//

#include <MyStepper.h>

// change this to fit the number of steps per revolution
// for your motor
int StepsPerRevolution = 200;

// Stepper motor drive pins
int PULSE_PIN = 13;
int DIR_PIN = 12;
int EN_PIN = 11;

// initialize the stepper library on pins 11 through 13:
MyStepper stepper(StepsPerRevolution, PULSE_PIN, DIR_PIN, EN_PIN);

void setup()
{
  stepper.SetSpeed(100); // Set Spped of Motor in RPM.
}

void loop()
{
  stepper.Steps(1); // Step by step
}
