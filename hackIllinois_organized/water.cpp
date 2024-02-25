#include <Arduino.h>

#include "water.h"
#include "motor.h"
#include "ultrasonic.h"

bool isWaterRunning = false;

void pourWater() {
  Serial.println("stop to pour water");
  float distance_to_cup = 100;
  while (distance_to_cup > kMaxCupDistance || distance_to_cup < kMinCupDistance) { // wait for the cup
    distance_to_cup = getDistance(CUP_TRIG_PIN, CUP_ECHO_PIN, kNumBeeps);
    Serial.println("waiting for cup...");
    Serial.print("distance: ");
    Serial.println(distance_to_cup);
    delay(5);
  }
  Serial.println("done waiting");
  //add timer?
  float distance_to_water = 3;
  while (distance_to_cup > kMinCupDistance && distance_to_cup < kMaxCupDistance) {  // cup is present
    Serial.println("cup present");
    distance_to_water = getDistance(WATER_TRIG_PIN, WATER_ECHO_PIN, kNumBeeps);
    distance_to_cup = getDistance(CUP_TRIG_PIN, CUP_ECHO_PIN, kNumBeeps);
    startWater();
    if (distance_to_water < kMinWaterDistance) { // cup is filled
      endWater();
      break;
    }
    delay(5);
  }
  endWater();
}

void startWater() {
  if (!isWaterRunning) {
    digitalWrite(WATER_MOTOR_PIN, HIGH);   
    Serial.println("water starting");
    isWaterRunning = true;
  }
}

void endWater() {
  if (isWaterRunning) {
    digitalWrite(WATER_MOTOR_PIN, LOW);    
    Serial.println("water stopping");
    isWaterRunning = false;
  }
}