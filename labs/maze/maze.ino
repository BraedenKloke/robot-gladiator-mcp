#include "helper.h"

int turn_count = 0;

void setup() {
  // put your setup code here, to run once:

  initialize_pins();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(measureDistance() > 10) {
    forward();
  } else if (measureDistance() < 5) {
    reverse();
  } else {
    stop();
  }

}
