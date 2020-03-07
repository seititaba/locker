/**
 * @file DoorLutti.h
 * @brief Use class stepper to control make a door
 * @author Lucas Seiti Taba
 * @date 06 Mar 2020
 */

#include "Arduino.h"
#include "StepperLutti.h"

/**
 * @class DoorLutti
 */
class DoorLutti
{
    public:

    DoorLutti(int steps_per_revolution, int motor_pin_1, int motor_pin_2,
              int motor_pin_3, int motor_pin_4) : stepper(steps_per_revolution, motor_pin_1, motor_pin_2,
              motor_pin_3, motor_pin_4) {}
    ~DoorLutti();

    void openDoor();
    void stopDoor();
    void resumeDoor();
    void closeDoor();

    private:

    char *name;
    StepperLutti stepper;    

};