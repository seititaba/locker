/*
 * StepperLutti.h - StepperLutti library for Wiring/Arduino - Version 2.0
 *
 * Original library             (0.1)   by Tom Igoe.
 * Two-wire modifications       (0.2)   by Sebastian Gassner
 * Combination version          (0.3)   by Tom Igoe and David Mellis
 * Bug fix for four-wire        (0.4)   by Tom Igoe, bug fix from Noah Shibley
 * High-speed stepping mod              by Eugene Kozlenko
 * Timer rollover fix                   by Eugene Kozlenko
 * Five phase five wire         (1.1.0) by Ryan Orendorff
 * Refactored version for Lutti (2.0)   by Lucas Seiti Taba
 *
 * The sequence of control signals for 4 control wires is as follows:
 *
 * Step C0 C1 C2 C3
 *    1  1  0  1  0
 *    2  0  1  1  0
 *    3  0  1  0  1
 *    4  1  0  0  1
 *
 * The circuits can be found at
 *
 * http://www.arduino.cc/en/Tutorial/Stepper
 * 
 * WARNING: THIS WILL NOT WORK PROPERLY WITH ANY KIND OF DELAY FUNCTIONS!!
 */

#include "Arduino.h"
#include "../src/StepperLutti.h"

/* @brief StepperLutti class constructor
/* It takes the number of steps and motor pins.
/* @author Lucas Seiti Taba */

StepperLutti::StepperLutti(int steps_per_revolution, int motor_pin_1, int motor_pin_2,
                                      int motor_pin_3, int motor_pin_4)
{

    this->current_step = 0;    // current step
    this->direction = 0;      // motor direction
    this->last_step_time = 0; // time stamp in us of the last step taken
    this->steps_per_revolution = steps_per_revolution; // total number of steps for this motor
    this->steps_left = 0;      // number os steps left

    this->motor_pin_1 = motor_pin_1;
    this->motor_pin_2 = motor_pin_2;
    this->motor_pin_3 = motor_pin_3;
    this->motor_pin_4 = motor_pin_4;

    /* @brief Arduino pinout setup
    /* @author Lucas Seiti Taba */

    pinMode(this->motor_pin_1, OUTPUT);
    pinMode(this->motor_pin_2, OUTPUT);
    pinMode(this->motor_pin_3, OUTPUT);
    pinMode(this->motor_pin_4, OUTPUT);

}

int StepperLutti::getStepsLeft(void)
{
    return this->steps_left;
}

/* @brif sets the speed in revs per minute
 * Converts input (in RPM) to millis
/* @author Lucas Seiti Taba */

void StepperLutti::setSpeed(long motor_speed)
{
  this->step_delay = 60L * 1000L * 1000L / this->steps_per_revolution / motor_speed;
}

/* @brief method to move motor
/* Moves the motor steps_to_move steps.  If the number is negative,
/* the motor moves in the reverse direction.
/* Note: This method take advantage of Arduino loop to work properly
/* and give a pseudo parallelism. DO NOT USE WITH OTHER DELAY FUNCTIONS!
/* @author Lucas Seiti Taba*/

void StepperLutti::step(int steps_to_move)
{
    if(this->steps_left == 0){
        this->steps_left = abs(steps_to_move);  // how many steps to take

        // determine direction based on whether steps_to_mode is + or -:

        if (steps_to_move > 0) { this->direction = 1; }
        if (steps_to_move < 0) { this->direction = 0; }

    }    

    else{
       
        unsigned long now = micros();
        // move only if the appropriate delay has passed:
        if (now - this->last_step_time >= this->step_delay)
        {
        // get the timeStamp of when you stepped:
        this->last_step_time = now;
        // increment or decrement the step number,
        // depending on direction:
        if (this->direction == 1)
        {
            this->current_step++;
            if (this->current_step == this->steps_per_revolution) {
            this->current_step = 0;
            }
        }
        else
        {
            if (this->current_step == 0) {
            this->current_step = this->steps_per_revolution;
            }
            this->current_step--;
        }
        // decrement the steps left:
        steps_left--;
        // step the motor to step number 0, 1, ..., {3 or 10} 
        stepMotor(this->current_step % 4);

    }

    // decrement the number of steps, moving one step each time:
    
  }
}

/*
 * Moves the motor forward or backwards.
 */
void StepperLutti::stepMotor(int thisStep)
{  
    switch (thisStep) {
      case 0:  // 1010
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, HIGH);
        digitalWrite(motor_pin_4, LOW);
      break;
      case 1:  // 0110
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, HIGH);
        digitalWrite(motor_pin_3, HIGH);
        digitalWrite(motor_pin_4, LOW);
      break;
      case 2:  //0101
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, HIGH);
        digitalWrite(motor_pin_3, LOW);
        digitalWrite(motor_pin_4, HIGH);
      break;
      case 3:  //1001
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, LOW);
        digitalWrite(motor_pin_4, HIGH);
      break;
    }
}

/*
  version() returns the version of the library:
*/
int StepperLutti::version(void)
{
  return 6;
}
