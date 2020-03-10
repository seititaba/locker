/**
 * @file LockerLutti.h
 * @brief A implementation of a locker. It user two step motors to achieve it's goal.
 * By design, both doors could work simultaneosly as it were two different process. 
 * Howeber, it's just a simulation.
 * NOTE - DO NOT USE THIS LIB WITH ANY KIND OF delay() FUNCTIONS. IT WILL NOT work
 * PROPERLY!
 * @author Lucas Seiti Taba
 * @date 08 Mar 2020
 * 
 */ 

#ifndef _LOCKERLUTTI_H
#define _LOCKERLUTTI_H

#include "StepperLutti.h"

class LockerLutti
{
    public:

    LockerLutti(int pin_1, int pin_2, int pin_3, int pin_4, int pin_5, int pin_6, int pin_7, int pin_8);
    ~LockerLutti();
    void openEntryDoor();
    void closeEntryDoor();
    void openExitDoor();
    void closeExitDoor();

    private:

    StepperLutti entry_door;
    StepperLutti exit_door;

    int max_steps;
    int speed;

};


#endif
