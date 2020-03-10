/**
 * @file StepperLutti.h 
 * @brief A Stepper class that allows to control multiple step motors simultaneosly.
 * This class is suited for 4 wires bipolar step motors, and give the proper interfaces
 * for make them spin clockwise or counterclockwise.
 * @author Lucas Seiti Taba
 * @date 07 Mar 2020
 * 
 */

#include "StepperLutti.h"

StepperLutti::StepperLutti(int pin_1, int pin_2, int pin_3, int pin_4) : motor(pin_1, pin_2, pin_3, pin_4)
{
    this->start_motor    = 0;
    this->step_delay     = 5000; // 5ms
    this->old_step_delay = 0;
    this->current_step   = 0;
    this->max_step       = 8192;
}

StepperLutti::~StepperLutti()
{
    this->motor.~StepperMotor();
}

void StepperLutti::clockWise()
{
#ifdef Arduino_h
    if(this->start_motor == 1 && this->current_step < this->max_step)
    {
        if(micros() - this->old_step_delay >= this->step_delay)
        { 
            this->motor.nextCoil();
            this->motor.runMotor();
            this->old_step_delay = micros();
            this->current_step++;
        }
    }
    else
    {
        this->stopMotor();
        this->motor.idleMotor();
        this->motor.runMotor();
    }    
#endif
}

void StepperLutti::counterClockWise()
{
#ifdef Arduino_h
    if(this->start_motor == 1 && this->current_step > 0)
    {
        if(micros() - this->old_step_delay >= this->step_delay)
        { 
            this->motor.prevCoil();
            this->motor.runMotor();
            this->old_step_delay = micros();
            this->current_step--;
        }
    } 
    else
    {
        this->stopMotor();
        this->motor.idleMotor();
        this->motor.runMotor();
    }
#endif
}

void StepperLutti::startMotor()
{
    this->start_motor = 1;
}

void StepperLutti::stopMotor()
{
    this->start_motor = 0;
}

void StepperLutti::setStepperSpeed(unsigned long speed)
{
    this->step_delay = speed;
}

void StepperLutti::setMaxStep(int max_step)
{
    this->max_step = max_step;
}