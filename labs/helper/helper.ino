#include "helper.h"

float LINEAR_SPEED, ANGULAR_SPEED;

void setup() {
  Serial.begin(9600);

  LINEAR_SPEED = 1;
  ANGULAR_SPEED = 1;
}

void loop() {
  // Obstacle Detection Tests
  if (isObstacleDetected()) {
    Serial.println("Infrared Sensor : YES");
  } else {
    Serial.println("Infrared Sensor : NO");
  }

  measureDistance();
}
