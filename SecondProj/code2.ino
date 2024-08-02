int buzzer = 12;
void setup()
{
  pinMode(buzzer, OUTPUT); 
}
void loop()
{
  int sound_duration = 500;
  for (int i = 0; i < 20; i++)
  {

    if (i < 5)
    {
      sound_duration = 500;
    } else if (i < 10)
    {
      sound_duration = 300;
    } else if (i < 20)
    {
      sound_duration = 100;
    }

    digitalWrite(buzzer, HIGH);
    delay(sound_duration);

    digitalWrite(buzzer, LOW);
    delay(sound_duration);
  }

  digitalWrite(buzzer, HIGH);
  delay(5000);
}