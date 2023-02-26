
#define led 4
#define BP 2
int state;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(BP, INPUT);
  
}

void loop()
{
//digitalWrite(led,digitalRead(BP));
  state=digitalRead(BP);//read button state
  digitalWrite(led,state);//write the button state to the LED
}
