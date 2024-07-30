#include "pitches.h"

const int potPin = A0;        // Potentiometer connected to analog pin A0
const int speakerPin = 8;     // Speaker connected to digital pin 8

// Define the melody for "Starman" (intro part)
int melody[] = {
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_D5,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_D5,
  NOTE_A4, NOTE_G4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_C5
};

// Define the duration of each note in the melody (1 = quarter note, 2 = half note, etc.)
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
  int potValue = analogRead(potPin); // Read the potentiometer value (0-1023)
  int volume = map(potValue, 0, 1023, 0, 255); // Map to a volume range (0-255)

  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(melody[0]); thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote]; // Note duration in milliseconds
    int noteFrequency = melody[thisNote];
    playNoteWithVolume(speakerPin, noteFrequency, noteDuration, volume);
    delay(noteDuration * 1.30); // Brief pause between notes (1.30 for a little legato effect)
  }

  delay(2000);  // Pause before repeating the melody
}

void playNoteWithVolume(int pin, int frequency, int duration, int volume) {
  int period = 1000000 / frequency;  // Period in microseconds
  int pulse = period / 2;  // 50% duty cycle
  long endTime = millis() + duration;

  while (millis() < endTime) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(pulse * volume / 255);
    digitalWrite(pin, LOW);
    delayMicroseconds(period - pulse * volume / 255);
  }
}