/**
 * @file StepperLutti.h
 * @brief StepperLutti library
 * Control 4 wired bipolar stepper motor
 * @author Lucas Seiti Taba
 * @date 06 march 2020
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
 * DONT EVEN TRY IT!!
 * 
 */

#ifndef _STEPPERLUTTI_H
#define _STEPPERLUTTI_H

/**
 * @class StepperLutti
 * @brief Defines a stepper motor
 * @param steps_per_revolution
 * @param motor_pin_1
 * @param motor_pin_2
 * @param motor_pin_3
 * @param motor_pin_4
 */ 

class StepperLutti
{
  public:

    StepperLutti(int steps_per_revolution, int motor_pin_1, int motor_pin_2,
                                 int motor_pin_3, int motor_pin_4);


    void setSpeed(long motor_speed);

    void step(int steps);

    int getStepsLeft(void);

    int getVersion(void);

  private:

    void stepMotor(int this_step);

    int direction;            // Direction of rotation
    unsigned long step_delay; // delay between steps, in ms, based on speed
    int steps_per_revolution;      // total number of steps this motor can take
    //int pin_count;            // how many pins are in use.
    int current_step;          // current step
    int steps_left;

    int motor_pin_1;
    int motor_pin_2;
    int motor_pin_3;
    int motor_pin_4;

    unsigned long last_step_time;
};

#endif