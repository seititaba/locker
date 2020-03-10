/**
 * @file LightLutti.h
 * @brief Defines hardware wiring and some functions to control light
 * @author Lucas Seiti Taba
 * @date 08 Mar 2020
 *
 */

#include "LightLutti.h"

LightLutti::LightLutti(int pin)
{
    this->pin = pin;
    this->pwm = 0;

#ifdef Arduino_h
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, HIGH);
#endif

}

LightLutti::~LightLutti()
{

}

void LightLutti::turnOnLight()
{
#ifdef Arduino_h    
    digitalWrite(this->pin, LOW);
#endif
}

void LightLutti::turnOffLight()
{
#ifdef Arduino_h    
    digitalWrite(this->pin, HIGH);
#endif
}

void LightLutti::lightModePWM(int pwm)
{
#ifdef Arduino_h    
    analogWrite(this->pin, pwm);
#endif
}
