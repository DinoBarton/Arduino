#include <Servo.h>

Servo myservo;              

void setup(){

  myservo.attach(10);
  myservo.write(90);
} 
 
void loop(){
  myservo.write(90);
  delay(500);
  myservo.write(60);
  delay(500);
  myservo.write(90);
  delay(500);
  myservo.write(150);
  delay(500);
}