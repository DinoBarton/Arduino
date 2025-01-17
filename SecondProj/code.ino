#include "pitches.h"

const int potPin = A0;   
const int speakerPin = 8;    

int melody[] = {
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_D5,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_D5,
  NOTE_A4, NOTE_G4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_C5
};

int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 4, 4, 2
};

void setup() {
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin); 
  int volume = map(potValue, 0, 1023, 0, 255); 

  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(melody[0]); thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote]; 
    int noteFrequency = melody[thisNote];
    playNoteWithVolume(speakerPin, noteFrequency, noteDuration, volume);
    delay(noteDuration * 1.30); 
  }

  delay(2000);
}

void playNoteWithVolume(int pin, int frequency, int duration, int volume) {
  int period = 1000000 / frequency;  
  int pulse = period / 2; 
  long endTime = millis() + duration;

  while (millis() < endTime) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(pulse * volume / 255);
    digitalWrite(pin, LOW);
    delayMicroseconds(period - pulse * volume / 255);
  }
}