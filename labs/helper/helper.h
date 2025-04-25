#ifndef __HELPER_H_
#define __HELPER_H_

// Derived experimentally in lab Measurements
extern float LINEAR_SPEED; // metres / second
extern float ANGULAR_SPEED; // degrees / second

// Nico: Students can initialize these variables in setup function
float LINEAR_SPEED, ANGULAR_SPEED;

#define B1A 12 // Right wheel forward
#define B1B 11 // Right wheel reverse
#define A1A 8 // Left wheel forward
#define A1B 7 // Left wheel reverse

#define PROXI 5 // Infrared sensor
// #define ULTRASONIC_TRIG 9
// #define ULTRASONIC_ECHO 10

// Pins
const int TRIG_PIN = 7;
const int ECHO_PIN = 8;

// Anything over 400 cm (23200 us pulse) is "out of range"
const unsigned int MAX_DIST = 23200;

void initializePins() {
  pinMode(B1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  pinMode(PROXI, INPUT);
  // pinMode(ULTRASONIC_TRIG, OUTPUT);
  // pinMode(ULTRASONIC_ECHO, INPUT);
  // The Trigger pin will tell the sensor to range find
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);

  //Set Echo pin as input to measure the duration of 
  //pulses coming back from the distance sensor
  pinMode(ECHO_PIN, INPUT);
}

// Deprecated
//
// Braeden: Incorrect naming convention. Functions should be camelCase 
// to match convention of Arduino built-in functions (e.g., digitalRead).
void initialize_pins() {
  initializePins();
}

void stop() {
  digitalWrite(B1A, false);
  digitalWrite(B1B, false);
  digitalWrite(A1A, false);
  digitalWrite(A1B, false);
}

void forward() {
  digitalWrite(B1A, true);
  digitalWrite(B1B, false);
  digitalWrite(A1A, true);
  digitalWrite(A1B, false);
}

// Moves robot forward x metres.
void forward(float x) {
  float t;

  t = x / LINEAR_SPEED; // metres / ( metres / second ) = seconds
  t = t * 1000; // convert to milliseconds

  forward();
  delay(t);
  stop();
}

void right() {
  digitalWrite(B1A, true);
  digitalWrite(B1B, false);
  digitalWrite(A1A, false);
  digitalWrite(A1B, true);
}

// Turns robot right x degrees.
void right(float x) {
  float t;

  t = x / ANGULAR_SPEED; // degrees / ( degrees / second ) = seconds
  t = t * 1000; // convert to milliseconds

  right();
  delay(t);
  stop();
}

void left() {
  digitalWrite(B1A, false);
  digitalWrite(B1B, true);
  digitalWrite(A1A, true);
  digitalWrite(A1B, false);
}

// Turns robot left x degrees.
void left(float x) {
  float t;

  t = x / ANGULAR_SPEED; // degrees / ( degrees / second ) = seconds
  t = t * 1000; // convert to milliseconds

  left();
  delay(t);
  stop();
}

void reverse() {
  digitalWrite(B1A, false);
  digitalWrite(B1B, true);
  digitalWrite(A1A, false);
  digitalWrite(A1B, true);
}

// Moves robot backward x metres.
void reverse(float x) {
  float t;

  t = x / LINEAR_SPEED; // metres / ( metres / second ) = seconds
  t = t * 1000; // convert to milliseconds

  reverse();
  delay(t);
  stop();
}

bool isObstacleDetected() {
  int sensorIn = digitalRead(PROXI);
  if (sensorIn == 1) {
    return false; // Nothing detected
  } else {
    return true;  // Detected
  }
}

void measureDistance() {
  // digitalWrite(ULTRASONIC_TRIG, LOW);
  // delayMicroseconds(2);
  // digitalWrite(ULTRASONIC_TRIG, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(ULTRASONIC_TRIG, LOW);

  // float duration = pulseIn(ULTRASONIC_ECHO, HIGH);
  
  // float speedOfSound = 0.0343; // c/mS
  // float distance = (duration * speedOfSound) / 2;

  // Serial.print("Dur");
  // Serial.print(duration);
  // Serial.print("Distance: ");
  // Serial.print(distance);
  // Serial.println();

  unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width;
  float cm;
  float inches;

  // Hold the trigger pin high for at least 10 us
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Wait for pulse on echo pin
  while ( digitalRead(ECHO_PIN) == 0 );

  // Measure how long the echo pin was held high (pulse width)
  // Note: the micros() counter will overflow after ~70 min
  t1 = micros();
  while ( digitalRead(ECHO_PIN) == 1);
  t2 = micros();
  pulse_width = t2 - t1;

  // Calculate distance in centimeters and inches. The constants
  // are found in the datasheet, and calculated from the assumed speed
  //of sound in air at sea level (~340 m/s).
  cm = pulse_width / 58.0;
  inches = pulse_width / 148.0;

  // Print out results
  if ( pulse_width > MAX_DIST ) {
    Serial.println("Out of range");
  } else {
    Serial.print(cm);
    Serial.print(" cm \t");
    Serial.print(inches);
    Serial.println(" in");
  }

  // Wait at least 60ms before next measurement
  delay(60);
}

#endif
