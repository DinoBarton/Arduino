//www.elegoo.com
//2016.12.08

int GreenledPin = 9;
int YellowledPin = 8;
int RedledPin = 7;
int buttonApin = 12;
int buttonBpin = 11;

void setup() 
{
  pinMode(GreenledPin, OUTPUT);
  pinMode(YellowledPin, OUTPUT);
  pinMode(RedledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  
}

void loop() 
{
  if (digitalRead(buttonApin) == LOW)
  { 
    digitalWrite(GreenledPin, HIGH);
    delay(500);
    digitalWrite(GreenledPin, LOW);
    digitalWrite(YellowledPin, HIGH);
    delay(500);
    digitalWrite(YellowledPin, LOW);
    digitalWrite(RedledPin, HIGH);
    delay(500);
    digitalWrite(RedledPin, LOW);
  }
  
  if (digitalRead(buttonBpin) == LOW)
  {
    digitalWrite(RedledPin, HIGH);
    delay(500);
    digitalWrite(RedledPin, LOW);
    digitalWrite(YellowledPin, HIGH);
    delay(500);
    digitalWrite(YellowledPin, LOW);
    digitalWrite(GreenledPin, HIGH);
    delay(500);
    digitalWrite(GreenledPin, LOW);
  }
}