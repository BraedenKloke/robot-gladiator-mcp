#include "helper.h"

float LINEAR_SPEED = 1.0; // m / s
float ANGULAR_SPEED = 1.0; // m / s

void setup() {
  initializePins();
}

void loop() {
  forward();
  delay(1000);
  
  stop();
  while(true);
}
