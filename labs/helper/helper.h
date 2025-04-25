#ifndef __HELPER_H_
#define __HELPER_H_

// Derived experimentally in lab Measurements
extern float LINEAR_SPEED; // metres / second
extern float ANGULAR_SPEED; // degrees / second

#define B1A 12 // Right wheel forward
#define B1B 11 // Right wheel reverse
#define A1A 8 // Left wheel forward
#define A1B 7 // Left wheel reverse

#define PROXI 5 // Infrared sensor

// Ultrasonic sensor 
#define TRIG_PIN 7
#define ECHO_PIN 8 

// Anything over 400 cm (23200 us pulse) is "out of range"
const unsigned int MAX_DIST = 23200;

void initializePins() {

  // Wheels
  pinMode(B1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);

  // Infrared sensor
  pinMode(PROXI, INPUT);

  // Ultrasonic sensor
  pinMode(TRIG_PIN, OUTPUT); // Commands the ultrasonic sensor to emit a ultrasonic wave
  digitalWrite(TRIG_PIN, LOW);
  pinMode(ECHO_PIN, INPUT); // Measures the returning ultrasonic wave
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

// Returns true if object detected by the infrared sensor, false otherwise.
bool isObstacleDetected() {
  int sensorIn = digitalRead(PROXI);
  if (sensorIn == 1) {
    return false; // Nothing detected
  } else {
    return true;  // Detected
  }
}

// Returns number of centimetres robot is distanced from an object.
float measureDistance() {
  // Ultrasonic Ranging Module HC - SRO4 Datasheet:
  // https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf
  const int MIN_TIME_BETWEEN_MEASUREMENTS = 60; // ms
  const int MIN_TRIGGER_SIGNAL_DURATION = 10; // us
  const int PULSE_WIDTH_TO_CM_CONVERSION_CONST = 58;

  unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width;
  float cm;
  float inches;

  // Hold the trigger pin high 
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(MIN_TRIGGER_SIGNAL_DURATION);
  digitalWrite(TRIG_PIN, LOW);

  // Wait for pulse on echo pin
  while ( digitalRead(ECHO_PIN) == 0 );

  // Measure how long the echo pin was held high (pulse width),
  // the micros() counter will overflow after ~70 min
  t1 = micros();
  while ( digitalRead(ECHO_PIN) == 1 );
  t2 = micros();
  pulse_width = t2 - t1;

  // Calculate distance in centimetres 
  cm = pulse_width / PULSE_WIDTH_TO_CM_CONVERSION_CONST;

  // Print out results
  if ( pulse_width > MAX_DIST ) {
    Serial.println("Out of range");
  } else {
    Serial.print(cm);
    Serial.println(" cm");
  }

  delay(MIN_TIME_BETWEEN_MEASUREMENTS);

  return cm;
}

#endif
