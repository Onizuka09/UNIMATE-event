
int trig = 6;
int echo = 9;
long lecture_echo;
long dist;

void setup(){

pinMode(trig, OUTPUT);
digitalWrite(trig, LOW);
pinMode(echo, INPUT);
Serial.begin(9600);

Serial.println ("capteur a distance ");
}

void loop(){

digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
lecture_echo = pulseIn(echo,HIGH);
dist = lecture_echo /58;
Serial.print("D=");
Serial.print(dist);
delay(500);

}
