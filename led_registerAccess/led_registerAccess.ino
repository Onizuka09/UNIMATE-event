
/**********************************
Controlling Internal LED (Pin 13) via regiters 

Arduino pin= 13 => Atmega328p Pin = PB5 

1- Set up the Pin mode (OUTPUT /INPUT) => the register that is responsible for that is DDRB 
2- Set up the value (1/0) => the regiter that is responsible for that is PORTB  
*************************************/
void setup() {

// set up the DDB5 to 1  
DDRB |=(1<<DDB5);

}


void loop() {
  //set up the PORTB5 to 1  
PORTB |=(1<<PORTB5); // turn ON LED 
delay(2000); // 2 seconds delay 
PORTB &= ~(1<<PORTB5) ; // turn OFF LED 
delay(2000);
}
