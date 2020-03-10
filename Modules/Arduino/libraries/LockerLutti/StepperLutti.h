/**
 * @file StepperLutti.h 
 * @brief A Stepper class that allows to control multiple step motors simultaneosly.
 * This class is suited for 4 wires bipolar step motors, and give the proper interfaces
 * for make them spin clockwise or counterclockwise.
 * @author Lucas Seiti Taba
 * @date 07 Mar 2020
 * 
 */

#ifndef _STEPPERLUTTI_H
#define _STEPPERLUTTI_H

#include "StepperMotor.h"

/**
 * @class StepperLutti
 * @brief Gives basic motor control such as rotation direction, start/stop control, and
 * speed control
 * @param pin_1 coil Blue
 * @param pin_2 coil Pink
 * @param pin_3 coil Yellow
 * @param pin_4 coil Orange
 */
class StepperLutti
{
    public:

    StepperLutti(int pin_1, int pin_2, int pin_3, int pin_4);
    ~StepperLutti();

    /**
     * @brief Motor rotates in clockwise direction until it reaches max_step (end of run)
     * or when it is commanded to (stop command)
     */
    void clockWise();

    /**
     * @brief Motor rotates in counter-clockwise direction until it reaches max_step (end
     * of run) or when it is commanded to (stop command)
     */
    void counterClockWise();

    void startMotor();
    void stopMotor();
    void setStepperSpeed(unsigned long speed); // RPM
    void setMaxStep(int max_step);

    private:

    int start_motor;
    unsigned long step_delay;
    unsigned long old_step_delay;
    int current_step;
    int max_step;
    StepperMotor motor;    
};
#endif
