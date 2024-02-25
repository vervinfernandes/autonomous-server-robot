#include "motor.h"

void setupMotors() {
  pinMode(LEFT_MOTOR_PIN_FOR, OUTPUT);
  pinMode(LEFT_MOTOR_PIN_BACK, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN_FOR, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN_BACK, OUTPUT);
  pinMode(WATER_MOTOR_PIN, OUTPUT);
}

void testWaterMotor() {
  analogWrite(WATER_MOTOR_PIN, 255);
  delay(10000);
  analogWrite(WATER_MOTOR_PIN, 0);
}

void leftMotor(int speed) {
  if (speed == 0) {
    analogWrite(LEFT_MOTOR_PIN_FOR, 0);
    analogWrite(LEFT_MOTOR_PIN_BACK, 0);
    Serial.println("left stop");
  } else if (speed < 0) {
    analogWrite(LEFT_MOTOR_PIN_FOR, 0);
    analogWrite(LEFT_MOTOR_PIN_BACK, abs(speed));
    Serial.println("left backwards");
  } else {
    analogWrite(LEFT_MOTOR_PIN_FOR, speed);
    analogWrite(LEFT_MOTOR_PIN_BACK, 0);
    Serial.println("left forward");
  }
}

void rightMotor(int speed) {
  if (speed == 0) {
    analogWrite(RIGHT_MOTOR_PIN_FOR, 0);
    analogWrite(RIGHT_MOTOR_PIN_BACK, 0);
    Serial.println("right stop");
  } else if (speed < 0) {
    analogWrite(RIGHT_MOTOR_PIN_FOR, 0);
    analogWrite(RIGHT_MOTOR_PIN_BACK, abs(speed));
    Serial.println("right backwards");
  } else {
    analogWrite(RIGHT_MOTOR_PIN_FOR, speed);
    analogWrite(RIGHT_MOTOR_PIN_BACK, 0);
    Serial.println("right forward");
  }
}