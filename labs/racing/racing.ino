/*
 * Objective
 * ---------
 * Write an algorithm for your robot to navigate a race course.
 */

// Pins
#define RIGHT_WHEEL_FORWARD 12 
#define LEFT_WHEEL_FORWARD 8 

// Robot speeds
//
// These values are derived experimentally in the Measurements lab
#define LINEAR_SPEED 5 // metres / millisecond
#define ANGULAR_SPEED 5 // degrees / millisecond

void setup() {
  pinMode(RIGHT_WHEEL_FORWARD, OUTPUT);
  pinMode(LEFT_WHEEL_FORWARD, OUTPUT);
}

void loop() {
  moveForward(1);
  turnRight(90);
}

/* 
 * Function: moveForward
 * ----------------------
 * Move forward x metres. 
 *
 * x: number of metres to move forward
 */
void moveForward(double x) {
  double t = x / LINEAR_SPEED; // milliseconds

  // Move forward for t milliseconds
  digitalWrite(LEFT_WHEEL_FORWARD, true);
  digitalWrite(RIGHT_WHEEL_FORWARD, true);
  delay(t);

  // Stop
  digitalWrite(LEFT_WHEEL_FORWARD, false);
  digitalWrite(RIGHT_WHEEL_FORWARD, false);
}

/* 
 * Function: turnRight
 * -------------------
 * Turn right x degrees.
 *
 * x: number of degrees to turn
 */
void turnRight(int x) {
  double t = x / ANGULAR_SPEED; // milliseconds

  // Turn right for t milliseconds
  digitalWrite(LEFT_WHEEL_FORWARD, true);
  delay(t);

  // Stop
  digitalWrite(LEFT_WHEEL_FORWARD, false);
}








