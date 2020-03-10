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

#include "LockerLutti.h"

LockerLutti::LockerLutti(int pin_1, int pin_2, int pin_3, int pin_4, int pin_5, int pin_6, int pin_7, int pin_8) : entry_door(pin_1, pin_2, pin_3, pin_4) , exit_door(pin_5, pin_6, pin_7, pin_8)
{
    this->max_steps = 8192;
    this->speed     = 60;
}

LockerLutti::~LockerLutti()
{

}

void LockerLutti::openEntryDoor()
{
    this->entry_door.clockWise;
    this->entry_door.startMotor;
}

void LockerLutti::closeEntryDoor()
{

}

void LockerLutti::openExitDoor()
{

}

void LockerLutti::closeExitDoor()
{

}