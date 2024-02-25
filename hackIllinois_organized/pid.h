#pragma once

#include <Arduino.h>

const float kP = 1;    // find through experimentation
const float kI = 0;  // set to 0 for now
const float kD = 15;     // find through experimentation
const uint8_t kMaxSpeed = 105; //old was 105
const int8_t kMinSpeed = -105; //old was 105
const uint8_t kBaseSpeed = 100;
const uint8_t kBlackMin = 850;

void PID_control();
