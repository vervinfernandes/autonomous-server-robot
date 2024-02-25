#pragma once

#include <Arduino.h>

#define WATER_TRIG_PIN 7 
#define WATER_ECHO_PIN 8   
#define CUP_TRIG_PIN 4  
#define CUP_ECHO_PIN 2

const uint8_t kNumBeeps = 5;
const float kMinCupDistance = 2; // cm
const float kMaxCupDistance = 7; // cm  
const float kMinWaterDistance = 9; // cm

void setupUltrasonic();

float getDistance(int trigPin, int echoPin, int n);