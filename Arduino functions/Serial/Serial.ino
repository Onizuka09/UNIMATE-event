// exercie 3 
String message ; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
 
  while(Serial.available() > 0) {
    // read the incoming string
message= Serial.readString();
   Serial.print("I received: ");
     Serial.println(message); 
 
  }
}
