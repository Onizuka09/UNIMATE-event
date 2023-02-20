
#include <RHReliableDatagram.h>
#include <RH_NRF24.h>
#include <SPI.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

//instance of the radio driver
RH_NRF24 driver;


RHReliableDatagram manager(driver, SERVER_ADDRESS);

int ena = 6 ; 
int enb = 3 ;  
int in1 = 9 ;
int in2 = 7 ;
int in3 = 5 ;  
int in4 = 2 ;
uint8_t data[] = "data recieved ";

uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
void setup() 
{
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);    
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  if (!manager.init())
    Serial.println("init failed");

}


void backward(){
digitalWrite(in1,1);
digitalWrite(in2,0);

digitalWrite(in3,1);
digitalWrite(in4,0);
}
void forward(){
digitalWrite(in1,0);
digitalWrite(in2,1);

digitalWrite(in3,0);
digitalWrite(in4,1);
  
}
void loop()
{
  if (manager.available())
  {
    // Wait for a message addressed to us from the client
    uint8_t len = sizeof(buf);
    uint8_t from;
    if (manager.recvfromAck(buf, &len, &from))
    {
      Serial.print("got request ");
         
      // Set Motor Direction
         backward();  
       
      }
     else {
      forward(); 
     }
     analogWrite(enb,buf[0]);     // speed motor right 
     analogWrite(ena,buf[1]);     // speed left motor  
      // Send a reply back to the originator client
      if (!manager.sendtoWait(data, sizeof(data), from))
        Serial.println("sendtoWait failed");
    }
  }
//}
