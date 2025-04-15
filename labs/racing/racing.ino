/*
 * Objective
 * ---------
 * Write an algorithm for your robot to navigate a race course.
 *
 * Coding convention: https://www.cs.swarthmore.edu/~newhall/unixhelp/c_codestyle.html
 */

// Pins
#define RIGHT_WHEEL_FORWARD 12 
#define RIGHT_WHEEL_REVERSE 11
#define LEFT_WHEEL_FORWARD 8 
#define LEFT_WHEEL_REVERSE 7

// Time constants
//
// These values are derived experimentally
#define TIME_FOR_30_DEGREE_TURN 500 // milliseconds
#define TIME_FOR_45_DEGREE_TURN 500 // milliseconds
#define TIME_FOR_90_DEGREE_TURN 500 // milliseconds

/* 
 * Function: setup
 * ---------------
 * Configures pins to behave as input or output.
 */
void setup() {
  pinMode(RIGHT_WHEEL_FORWARD, OUTPUT);
  pinMode(RIGHT_WHEEL_REVERSE, OUTPUT);
  pinMode(LEFT_WHEEL_FORWARD, OUTPUT);
  pinMode(LEFT_WHEEL_REVERSE, OUTPUT);
}

void loop() {
  
  digitalWrite(LEFT_WHEEL_FORWARD, false);
  delay(TIME_FOR_45_DEGREE_TURN); 

  // Move forward
  digitalWrite(LEFT_WHEEL_FORWARD, true);
  digitalWrite(RIGHT_WHEEL_FORWARD, true);
}

/* 
 * Function: move_forward
 * ----------------------
 * Moves the robot forward x centimetres then stops the robot.
 *
 * x: number of centimetres to travel
 */
 void move_forward(x) {
  digitalWrite(LEFT_WHEEL_FORWARD, true);
  digitalWrite(RIGHT_WHEEL_FORWARD, true);
  delay()

  digitalWrite(LEFT_WHEEL_FORWARD, false);
  digitalWrite(RIGHT_WHEEL_FORWARD, false);
 }










