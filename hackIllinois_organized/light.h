#pragma once

#include <Arduino.h>

#define LEFT_SENSOR_PIN 1
#define RIGHT_SENSOR_PIN 2
#define FARLEFT_SENSOR_PIN 3

void setupLightSensor();

int getLightVal(int pin, int n);