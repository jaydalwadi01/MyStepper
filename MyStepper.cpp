//**************************************************************************//
//*************************** Created by ***********************************//
//*********************** Author : Jay Dalwadi *****************************//
//******** Github Link: https://github.com/jaydalwadi01/MyStepper **********//
//************************** Library File **********************************//
//**************************************************************************//

#include "MyStepper.h"

MyStepper::MyStepper(int steps_for_rev, int pulse_pin, int dir_pin, int en_pin)
{
  this->dir = 0;
  this->num_of_steps = steps_for_rev;
  
  this->pulse_pin = pulse_pin;
  this->dir_pin = dir_pin;
  this->en_pin = en_pin;

  pinMode(this->pulse_pin, OUTPUT);
  pinMode(this->dir_pin, OUTPUT);
  pinMode(this->en_pin, OUTPUT);
  
  this->last_step_time = 0; 
}

MyStepper::Steps(int steps)
{
  int steps_to_move = abs(steps);

  if(steps > 0)
  {
    dir = HIGH;
  }
  if(steps < 0)
  {
    dir = LOW;
  }
  
  digitalWrite(this->dir_pin, dir);
  digitalWrite(this->en_pin, HIGH);
  
  if(steps == 0)
  {
	  MyStepper::Stop();
  }
  
  this->event = 0;
  
  while (steps_to_move > 0)
  {
    unsigned long now = micros(); 
    if(now - this->last_step_time >= this->step_delay && this->event == 0)
    {
      this->last_step_time = now;
      digitalWrite(this->pulse_pin, HIGH);
      this->event = 1;      
    }
    if((now - this->last_step_time >= this->step_delay) && this->event == 1)
    {
      this->last_step_time = now;
      digitalWrite(this->pulse_pin, LOW);
      this->event = 0;
      steps_to_move--;
    }
  }
  
  digitalWrite(this->en_pin, LOW);
}

MyStepper::OneRevolution(bool d)
{
  digitalWrite(this->dir_pin, d);
  
  digitalWrite(this->en_pin, HIGH);
  
  int steps_per_rev = this->num_of_steps;
  
  this->event = 0;
  
  while (steps_per_rev > 0)
  {
    unsigned long now = micros();
    if(now - this->last_step_time >= this->step_delay && this->event == 0)
    {
      this->last_step_time = now;
      digitalWrite(this->pulse_pin, HIGH);
      this->event = 1;      
    }
    if((now - this->last_step_time >= this->step_delay) && this->event == 1)
    {
      this->last_step_time = now;
      digitalWrite(this->pulse_pin, LOW);
      this->event = 0;
      steps_per_rev--;
    }
  }
  
  digitalWrite(this->en_pin, LOW);
}

MyStepper::SetSpeed(long rpm)
{
  this->step_delay = 60UL * 1000UL * 1000UL / this->num_of_steps / rpm / 2;
}

MyStepper::Stop()
{
  digitalWrite(this->en_pin, LOW);
}