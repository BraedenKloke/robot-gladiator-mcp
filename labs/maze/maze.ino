#include "helper.h"

int turn_count = 0;

void setup() {
  // put your setup code here, to run once:

  initialize_pins();
  forward();
  delay(1000);
  reverse();
  delay(1000);
  right();
  delay(1000);
  left();
  delay(1000);
  stop();
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();

  if(!digitalRead(PROXI)) { 
    if(turn_count < 1) {
      turn_count++;
      left();
      delay(300);
    } else {
      turn_count = 0;
      right();
      delay(600);
    }
  } else {
    turn_count = 0;
    delay(100);
  }

}
