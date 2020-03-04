#include "StepperLutti.h"
 
const int stepsPerRevolution = 512; 
  
//Inicializa a biblioteca utilizando as portas de 8 a 11 para 
//ligacao ao motor 
StepperLutti myStepper(stepsPerRevolution, 8,10,9,11);
StepperLutti myStepper2(stepsPerRevolution, 4,6,5,7); 

  
void setup() 
{ 
 //Determina a velocidade inicial do motor 
 myStepper.setSpeed(60);
 myStepper2.setSpeed(60);
 myStepper.step(2048);
 while(myStepper.getStepsLeft() > 0){
  myStepper.step(4096);
 }
 
} 
  
void loop() 
{ 


 //myStepper.step(1000);
 //myStepper2.step(-1000);


}
