/**
 * @file LightLutti.h
 * @brief Defines hardware wiring and some functions to control light
 * @author Lucas Seiti Taba
 * @date 08 Mar 2020
 *
 */

#ifndef _LIGHTLUTTI_H
#define _LIGHTLUTTI_H

#include "Arduino.h"

class LightLutti
{
    public:

    LightLutti(int pin);
    ~LightLutti();
    void turnOnLight();
    void turnOffLight();
    void lightModePWM(int pwm);

    private:

    int pin;
    int pwm;

};

#endif