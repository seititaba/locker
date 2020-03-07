#include "StepperLutti.h"

StepperLutti m1(4,6,5,7);
StepperLutti m2(8,10,9,11);

unsigned long old_millis = 0;
bool flag = true;

void setup()
{
m1.startMotor();
m2.startMotor();
Serial.begin(9600);
//while(1)
//{
//  m1.motorPowerCoil(i);
//  if(i < 0)
//  {
//    i = 4;
//  }
//  else
//  {
//    i--;
//  }
// delayMicroseconds(5000);
//}

}

void loop()
{
  if(flag)
  {
    m2.clockWise();
    m1.counterClockWise();
  }
  else
  {
    m1.clockWise();
    m2.counterClockWise();
  }
  if(millis() - old_millis >= 1000)
  {
    flag = !flag;
    //m2.stopMotor();
    //m1.stopMotor();
    //m2.startMotor();
    //m1.startMotor();
    old_millis = millis();
  }

}
