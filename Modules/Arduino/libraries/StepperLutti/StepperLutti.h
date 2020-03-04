/*
 * @file StepperLutti.h
 * @brief StepperLutti library for Wiring/Arduino - Version 2.0
 * @author Lucas Seiti Taba
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
 * 
 */

#ifndef StepperLutti_h
#define StepperLutti_h

s
/* @class StepperLutti
 * @brief Defines a stepper motor
 * @param steps_per_revolution
 * @param motor_pin_1
 * @param motor_pin_2
 * @param motor_pin_3
 * @param motor_pin_4
 *  
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