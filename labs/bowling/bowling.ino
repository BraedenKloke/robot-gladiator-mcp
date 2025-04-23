/**
The objective of this lab is write an algorithm for your robot to knock over a set of toilet paper rolls
arranged in various shapes (e.g., triangle, square, half-moon, etc.).

The challenge of this lab is finding the correct balance between the time you allow your robot to turn
and the sensor sampling rate.
*/

// Pins
#define RIGHT_WHEEL_FORWARD 12 
#define RIGHT_WHEEL_REVERSE 11
#define LEFT_WHEEL_FORWARD 8 
#define LEFT_WHEEL_REVERSE 7
#define PROXIMITY_SENSOR 5 

// Time constants
//
// These values are derived experimentally
#define TIME_FOR_30_DEGREE_TURN 500 // milliseconds
#define TIME_FOR_45_DEGREE_TURN 500 // milliseconds
#define TIME_FOR_90_DEGREE_TURN 500 // milliseconds
#define PROXIMITY_SENSOR_SAMPLING_RATE 1000 // milliseconds

void setup() {
  // Configure pins to behave as an input or output
  pinMode(RIGHT_WHEEL_FORWARD, OUTPUT);
  pinMode(RIGHT_WHEEL_REVERSE, OUTPUT);
  pinMode(LEFT_WHEEL_FORWARD, OUTPUT);
  pinMode(LEFT_WHEEL_REVERSE, OUTPUT);
  pinMode(PROXIMITY_SENSOR, INPUT);
}

void loop() {
  // Read sensor
  bool object_detected = digitalRead(PROXIMITY_SENSOR) == false;

  if(object_detected){
    // Turn right 45 degrees
    digitalWrite(LEFT_WHEEL_FORWARD, false);
    delay(TIME_FOR_45_DEGREE_TURN); 
  } 

  // Move forward
  digitalWrite(LEFT_WHEEL_FORWARD, true);
  digitalWrite(RIGHT_WHEEL_FORWARD, true);

  // Wait a bit until next sensor reading
  delay(PROXIMITY_SENSOR_SAMPLING_RATE);
}
