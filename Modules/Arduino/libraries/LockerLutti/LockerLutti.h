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
class LockerLutti : public StepperLutti
{
    public:

    LockerLutti();
    ~LockerLutti();

    void openEntry();
    void stopEntry();
    void resumeEntry();
    void closeEntry();
    void openExit();
    void stopExit();
    void resumeExit();
    void closeExit();

    private:

    char *name;
    StepperLutti stepper;    

};