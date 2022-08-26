/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial

  by Dejan Nedelkovski,
  www.HowToMechatronics.com

*/
#include "pitches.h"
int speed=90;  //higher value, slower notes



// ULTRASONIC SENSOR CODE.

// defines pins numbers
const int trigPin = 24;
const int echoPin = 22;
const int trigPin2 = 40;
const int echoPin2 = 34;
const int speakerPin = 44;

// defines variables
long duration;
int distance;
void setup() {

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  Serial.begin(115200); // Starts the serial communication
}
void loop() {
  // READ LEFT
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  if (distance <= 220)
  {
    if (distance < 150)
    {
      // Play a tone to alert the user of the distance.
      tone(speakerPin, 700);
      delay(10);
      noTone(speakerPin);
    }
    // Valid and acceptable distance.
  }
  // Prints the distance on the Serial Monitor
  

  // READ RIGHT
  // Clears the trigPin
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(1);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  if (distance <= 220)
  {
    if (distance < 150)
    {
      // Play a tone to alert the user of the distance.
      tone(speakerPin, 1200);
      delay(10);
      noTone(speakerPin);
    }
  }
  // Prints the distance on the Serial Monitor

}
