/**
 * @file StepperMotor.h 
 * @brief A Stepper class that allows to control multiple step motors simultaneosly.
 * This class is suited for 4 wires bipolar step motors, and give the proper interfaces
 * for make them spin clockwise or counterclockwise. For this development,  28BYJ-48 – 5V
 * Stepper Motor were used.
 * A typical 4 wire control diagram is shown above:
 * 
 *     A   B   C   D
 * 1-  1   0   1   0
 * 2-  0   1   1   0
 * 3-  0   1   0   1
 * 4-  0   0   1   1
 * 
 * NOTE - DO NOT USE THIS CLASS WITH delay() OR SIMILAR FUNCTIONS, UNESPECTED BEHAVIOUR
 * MAY OCCUR!! 
 * 
 * @author Lucas Seiti Taba
 * @date 07 Mar 2020
 * 
 */

#ifndef _STEPPERMOTOR_H
#define _STEPPERMOTOR_H

//#include "Arduino.h"

/**
 * @class StepperMotor
 * @brief Defines a stepper motor, hard wire interface, through pin assignment, and expected
 * behaviour.
 * @param pin_1 coil Blue
 * @param pin_2 coil Pink
 * @param pin_3 coil Yellow
 * @param pin_4 coil Orange
 */
class StepperMotor
{
    public:

    StepperMotor(int pin_1, int pin_2, int pin_3, int pin_4);
    ~StepperMotor();
    
    /**
     * @fn motorPowerCoil
     * @brief Gives possibles coil configurations
     * @param coil coil configuration to be used
     */
    void motorPowerCoil(int coil);

    /**
     * @brief Get the next coil configuration. Used for a clockwise movement
     */
    void nextCoil();

    /**
     * @brief Get the previous coil configuration. Used for a counter-clockwise movement
     */
    void prevCoil();

    /**
     * @brief Power off motor to savy some energy
     */
    void idleMotor();

    /**
     * @brief Run motor throug select sequence (clockwise or counter-clockwise)
     */
    void runMotor();

    private:

    int pin_1;
    int pin_2;
    int pin_3;
    int pin_4;

    int current_coil;

};

#endif