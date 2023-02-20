/**********************************
* .
* 
* 
************************************/


#ifndef led_LIB_h
#define led_LIB_h
#include <Arduino.h>




class Led_LIB{
public : 
  // a contructor to set up a pin and delay 
    Led_LIB(int pin,int Delay);
    void on(); //Method (function) to turn on led 
    void off();//Method (function) to turn off led 
    void toggle();
    int _pin; 
    int _Delay;


  
};





#endif 
