#include "light.h"

void setupLightSensor() {
  pinMode(LEFT_SENSOR_PIN, INPUT);
  pinMode(RIGHT_SENSOR_PIN, INPUT);
  pinMode(FARLEFT_SENSOR_PIN, INPUT);
}

int getLightVal(int pin, int n) {
  int sum_vals = 0;

  for (int i = 0; i < n; i++) {
    sum_vals += analogRead(pin);
    //delay(5);
    delay(1);
  }
  sum_vals /= n;

  return sum_vals;
}