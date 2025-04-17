/*
 * Moves robot forward in a straight line.
 */

// Pins
#define RIGHT_WHEEL_FORWARD 12 
#define LEFT_WHEEL_FORWARD 8 

void setup() {
  pinMode(RIGHT_WHEEL_FORWARD, OUTPUT);
  pinMode(LEFT_WHEEL_FORWARD, OUTPUT);
}

void loop() {
  digitalWrite(RIGHT_WHEEL_FORWARD, true);
  digitalWrite(LEFT_WHEEL_FORWARD, true);
}
