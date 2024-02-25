#pragma once

#include <Arduino.h>

#define LEFT_MOTOR_PIN_FOR 6
#define LEFT_MOTOR_PIN_BACK 5  // OPTIONAL
#define RIGHT_MOTOR_PIN_FOR 11
#define RIGHT_MOTOR_PIN_BACK 10  // OPTIONAL
#define WATER_MOTOR_PIN 3

void setupMotors();

void testWaterMotor();

void leftMotor(int speed);

void rightMotor(int speed);