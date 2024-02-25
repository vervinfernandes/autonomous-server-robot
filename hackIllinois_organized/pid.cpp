#include "pid.h"
#include "motor.h"
#include "light.h"
#include "ultrasonic.h"

uint8_t lastError = 0;
int I = 0;

void PID_control() {
  int left = 0, right = 0, farLeft = 0;
  while (!(farLeft > kBlackMin && left > kBlackMin && right > kBlackMin)) {
    left = getLightVal(LEFT_SENSOR_PIN, kNumBeeps); 
    right = getLightVal(RIGHT_SENSOR_PIN, kNumBeeps);
    farLeft = getLightVal(FARLEFT_SENSOR_PIN, kNumBeeps);

    if (farLeft > kBlackMin) break;
    
    int error = left - right;
    int P = error;
    I = I + error;
    int D = error - lastError;
    lastError = error;
    int motorspeed = P * kP + I * kI + D * kD; //P * kP + I * kI + D * kD

    int motorSpeedLeft = kBaseSpeed + motorspeed;
    int motorSpeedRight = kBaseSpeed - motorspeed;

    if (motorSpeedLeft > kMaxSpeed)
      motorSpeedLeft = kMaxSpeed;
    if (motorSpeedRight > kMaxSpeed)
      motorSpeedRight = kMaxSpeed;
    if (motorSpeedLeft < kMinSpeed)
      motorSpeedLeft = kMinSpeed;
    if (motorSpeedRight < kMinSpeed)
      motorSpeedRight = kMinSpeed;

    motorSpeedLeft += 75; //old speed was 150
    motorSpeedRight += 75;

    leftMotor(motorSpeedLeft);
    rightMotor(motorSpeedRight);
  }
}
