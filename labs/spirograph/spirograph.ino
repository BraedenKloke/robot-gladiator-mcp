#include "helper.h"

void setup() {
  initialize_pins();
}

void loop() {
  if(isObstacleDetected()){
    stop();
  }else{
    forward();
  }
}