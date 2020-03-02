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

#ifndef StepperLutti_h
#define StepperLutti_h

/* @brief class for a bipolar phase stepper motor
/* A class modified from Stepper.h, that allows to use mode than one step motor simutaneosly.
/* @author Lucas Seiti Taba */

class StepperLutti
{
  public:

    /* @brief class constructor
    /* Class take steps per revolution and motor pins as input
    /* @author Lucas Seiti Taba */

    StepperLutti(int steps_per_revolution, int motor_pin_1, int motor_pin_2,
                                 int motor_pin_3, int motor_pin_4);

    /* @brief method for set motor speed
    /* Speed given in RPM. It is used to calculate step_delay.
    /* @author Lucas Seiti Taba */

    void setSpeed(long motor_speed);

    /* @brief method for move X steps
    /* @author Lucas Seiti Taba */

    void step(int steps);

    /* @brief method for get current steps left
    /* Return steps_left
    /* @author Lucas Seiti Taba */

    int getStepsLeft(void);

    /* @brief method for get current version
    /* Return version
    /* @author Lucas Seiti Taba */

    int getVersion(void);

  private:

    void stepMotor(int this_step);

    /* @brief motor variables
    /* Variables of direction, current step, numer of steps per revolution, and delay per step.
    /* @author Lucas Seiti Taba */

    int direction;            // Direction of rotation
    unsigned long step_delay; // delay between steps, in ms, based on speed
    int steps_per_revolution;      // total number of steps this motor can take
    //int pin_count;            // how many pins are in use.
    int current_step;          // current step
    int steps_left;

    /* @brief physical motors pins
    /* @author Lucas Seiti Taba */

    int motor_pin_1;
    int motor_pin_2;
    int motor_pin_3;
    int motor_pin_4;

    /* @brief timestamp in us of when the last step was taken
    /* @author Lucas Seiti Taba */

    unsigned long last_step_time;
};

#endif