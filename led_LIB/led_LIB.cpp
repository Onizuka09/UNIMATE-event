#include "led_LIB.h"


Led_LIB::Led_LIB(int pin,int Delay){
  _pin=pin; 
  _Delay=Delay;
  pinMode(_pin,OUTPUT); // set up the pinMode 
}


void Led_LIB::on(){

digitalWrite(_pin,1); 
  
}
void Led_LIB::off(){

digitalWrite(_pin,0); 

  
}
void Led_LIB::toggle(){

digitalWrite(_pin,1); 
delay(_Delay);
digitalWrite(_pin,0); 
delay(_Delay);  
}
