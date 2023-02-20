#include "led_LIB.h"

int pin = 13;  
int Delay=1000;  


Led_LIB  led(pin,Delay);


void setup() {

// create an object called LED and pass as pra  

}

void loop() {
led.toggle();

}
