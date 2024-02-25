#include <Arduino.h>
#include "motor.h"
#include "light.h"
#include "ultrasonic.h"
#include "pid.h"
#include "water.h"

void setup() {
  Serial.begin(9600);
  Serial.println("setup...");
  setupLightSensor();
  setupUltrasonic();
  setupMotors();
}

void loop() { // each iteration is one table

  PID_control();

  leftMotor(0);
  rightMotor(0);

  // pourWater();

  // leftMotor(110);
  // rightMotor(110);
  // delay(500);

}
