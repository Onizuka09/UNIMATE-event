
//handle communication protocols 
#include <RHReliableDatagram.h>
//driver 
#include <RH_NRF24.h> 
#include <SPI.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2
#define Yaxe A0
#define Xaxe A1

// instance of the radio driver
RH_NRF24 driver;

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram manager(driver, CLIENT_ADDRESS);

// declare unsigned 8-bit data array 
// 2 bytes  for motor speed and 1 byte for direction  /*****/
uint8_t data[3] ;

//uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN]; // a buffer to load in the ack message 

//joystick at Init position  
int x= 512 ; 
int y =512 ; 

void setup() 
{
  pinMode(Yaxe,INPUT);
  pinMode(Xaxe,INPUT); 
  
  Serial.begin(9600);

  // Initialize RadioManager with defaults - 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!manager.init())
    Serial.println("init failed");
  

  data[2]= 0 ;// forward 
}

void loop()
{
  y = analogRead(Yaxe); // read y 
  x=analogRead(Xaxe); //read x 

if(y<460 ){
// move backward /**************/
 data[2]=1 ; 
// set motor spped 
y=(y-460)*-1 ;// to reverse the readings ( - ) 
 // set the speed 
 data[0]= map(y,0,460,0,255); 
 data[1]= map(y,0,460,0,255); 
}
else if ( y > 564 ){
// move forwards /**************/  
data[2] = 0 ;  
// set motors speed 
data[0]= map(y,564,1023,0,255); 
 data[1]= map(y, 564,1023,0,255); 
}
else {
  data[0]= 0  ;
 data[1]= 0 ;
}

if (x< 460 ) {
  // move left 
x=(x-460)*-1 ; 
x= map(x,0,460,0,255); 
data[0]=data[0]+x ; // set the right motor spped in the forward direction 
data[1] =data[1]-x ;// set the motor speed in th backward directon   
if (data[0] > 255 ) 
  data[0]= 255 ; 
if (data[1]< 0) 
  data [1]= 0 ; 
}
else if (x > 564 ){ 
  // move right 
x = map (x,546,1023,0,255);
data[0]=data[0]-x ; // set the right motor spped in the forward direction 
data[1] =data[1]+x ;// set the left motor speed in th backward directon   
if (data[1] > 255 ) 
  data[1]= 255 ; 
if (data[0]< 0) 
  data[0]= 0 ;  
}


if (data[1] < 8 ) 
  data[1]= 0 ; 
if (data [0]< 8) 
  data[0]= 0 ; 
  
   
  
  //Serial.println("Sending to nrf24_reliable_datagram_server");
    
  // Send a message to manager_server rec
  uint8_t res=manager.sendtoWait(data, sizeof(data), SERVER_ADDRESS);
  // testing purposes 
  /* 
  if (res)
  {
    // Now wait for a reply from the server
    uint8_t len = sizeof(buf); // len form buff
    uint8_t from;   // var that contains the adress of the reciver
    if (manager.recvfromAckTimeout(buf, &len, 2000, &from))
    {
      Serial.print("got reply ");
     
    }
    else
    {
      Serial.println("No reply, is nrf24_reliable_datagram_server running?");
    }
  }
  else{
    Serial.println("sendtoWait failed");
  }*/
  delay(50);
}
