//**************************************************************************//
//*************************** Created by ***********************************//
//*********************** Author : Jay Dalwadi *****************************//
//******** Github Link: https://github.com/jaydalwadi01/MyStepper **********//
//************************** Library File **********************************//
//**************************************************************************//

#ifndef MyStepper_h
#define MyStepper_h

#if (ARDUINO >= 100)
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class MyStepper
{
  public:
    MyStepper(int steps_for_rev, int pulse_pin, int dir_pin, int en_pin);
    Steps(int num_of_steps);
    OneRevolution(bool d);
    SetSpeed(long rpm);
	Stop();

  private:
    int pulse_pin;
    int dir_pin;
    int en_pin;

    unsigned long step_delay;
    unsigned long last_step_time ;

    int dir;
    int num_of_steps;

    bool event;
};

#endif