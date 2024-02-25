#include "ultrasonic.h"
#include "motor.h"

void setupUltrasonic() {
  // configure the trigger pins to output mode
  pinMode(WATER_TRIG_PIN, OUTPUT);  
  pinMode(CUP_TRIG_PIN, OUTPUT);

  // configure the echo pins to input mode
  pinMode(WATER_ECHO_PIN, INPUT);
  pinMode(CUP_ECHO_PIN, INPUT);
}

float getDistance(int trigPin, int echoPin, int n) {
  float distance_cm = 0.0;
  for (unsigned i = 0; i < n; i++) {
    // generate 10-microsecond pulse to TRIG pin
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // measure duration of pulse from ECHO pin
    float duration_us = pulseIn(echoPin, HIGH); // microseconds

    // calculate the distance
    distance_cm += 0.017 * duration_us;

    delay(5); // miliseconds
  }
  distance_cm /= n;
  return distance_cm;
}