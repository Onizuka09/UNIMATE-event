#define pot  A3 
#define led  11 
int pot_val;
int led_val;
void setup(){
  pinMode(led,OUTPUT);
  pinMode(pot,INPUT);
  Serial.begin(9600);
}
void loop(){
 pot_val =analogRead(pot);
Serial.print("pot: "); 
Serial.print(pot_val);  
  led_val=map(pot_val,0,1023,0,255);
    Serial.print("   led: "); 
  Serial.println(led_val); 
   analogWrite(led,led_val);
  
} 
