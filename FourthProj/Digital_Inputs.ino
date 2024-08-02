int buttonApin = 12;
int buttonBpin = 13;
int ledpin = 9;

void setup() 
{
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);
  pinMode(ledpin, OUTPUT);
}

void loop() 
{
  
  if (digitalRead(buttonApin) == LOW)
  { 
    digitalWrite(ledpin, HIGH);
  }
  
  if (digitalRead(buttonBpin) == LOW)
  {
    digitalWrite(ledpin, LOW);
  }
}
