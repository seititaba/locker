#include "LightLutti.h"

int pin_logo  = 3;
int pin_room  = 4;
int pin_entry = 5;
int pin_exit  = 6;

LightLutti light(pin_logo);
LightLutti room(pin_room);
LightLutti authorized_entry(pin_entry);
LightLutti authorized_exit(pin_exit);

void setup()
{
    Serial.begin(9600);    
}

void loop()
{
    if(Serial.available())
    {
        delay(50);
        int cmd = Serial.read();
        if(cmd == 49)
        {
            light.turnOnLight();
        }
        if(cmd == 50)
        {
            light.turnOffLight();
        }
        if(cmd == 51)
        {
            room.turnOnLight();
        }
        if(cmd == 52)
        {
            room.turnOffLight();
        }
        if(cmd == 53)
        {
            authorized_entry.turnOnLight();
        }
        if(cmd == 54)
        {
            authorized_entry.turnOffLight();
        }
        if(cmd == 55)
        {
            authorized_exit.turnOnLight();
        }
        if(cmd == 56)
        {
            authorized_exit.turnOffLight();
        }
        
    }
}