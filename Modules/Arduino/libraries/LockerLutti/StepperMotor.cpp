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

#include "StepperMotor.h"

StepperMotor::StepperMotor(int pin_1, int pin_2, int pin_3, int pin_4)
{
    this->pin_1        = pin_1;
    this->pin_2        = pin_2;
    this->pin_3        = pin_3;
    this->pin_4        = pin_4;
    this->current_coil = 0;

#ifdef Arduino_h
    pinMode(this->pin_1, OUTPUT);
    pinMode(this->pin_2, OUTPUT);
    pinMode(this->pin_3, OUTPUT);
    pinMode(this->pin_4, OUTPUT);
#endif

}

StepperMotor::~StepperMotor()
{
#ifdef Arduino_h
    this->motorPowerCoil(4);
#endif
}

void StepperMotor::motorPowerCoil(int coil)
{
#ifdef Arduino_h
    switch (coil) {
      case 0:  // 1010
        digitalWrite(this->pin_1, HIGH);
        digitalWrite(this->pin_2, LOW);
        digitalWrite(this->pin_3, HIGH);
        digitalWrite(this->pin_4, LOW);
      break;
      case 1:  // 0110
        digitalWrite(this->pin_1, LOW);
        digitalWrite(this->pin_2, HIGH);
        digitalWrite(this->pin_3, HIGH);
        digitalWrite(this->pin_4, LOW);
      break;
      case 2:  //0101
        digitalWrite(this->pin_1, LOW);
        digitalWrite(this->pin_2, HIGH);
        digitalWrite(this->pin_3, LOW);
        digitalWrite(this->pin_4, HIGH);
      break;
      case 3:  //1001
        digitalWrite(this->pin_1, HIGH);
        digitalWrite(this->pin_2, LOW);
        digitalWrite(this->pin_3, LOW);
        digitalWrite(this->pin_4, HIGH);
      break;
      case 4:  //0000
        digitalWrite(this->pin_1, LOW);
        digitalWrite(this->pin_2, LOW);
        digitalWrite(this->pin_3, LOW);
        digitalWrite(this->pin_4, LOW);
      break;
    }
#endif
}

void StepperMotor::runMotor()
{
    this->motorPowerCoil(this->current_coil);
}

void StepperMotor::nextCoil()
{
    this->current_coil++;
    if(this->current_coil > 3)
    {
        this->current_coil = 0;
    }
}

void StepperMotor::prevCoil()
{
    this->current_coil--;
    if(this->current_coil < 0)
    {
        this->current_coil = 3;
    }
}

void StepperMotor::idleMotor()
{
    this->current_coil = 4;
}