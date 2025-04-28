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
#define TRIG_PIN 2
#define ECHO_PIN 9


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
  pinMode(ECHO_PIN, INPUT_PULLUP); // Measures the returning ultrasonic wave
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

  const int MAX_DISTANCE = 100; // 100 cm, Braeden: How is this calculated? Sasi: Arbitrary
  const int MIN_TIME_BETWEEN_MEASUREMENTS = 60; // ms
  const int MIN_TRIGGER_SIGNAL_DURATION = 10; // us
  // distance = pulse_width(2*us) * m/s * s/ms * ms/us * cm/m * 1/2
  const float PULSE_WIDTH_TO_CM_CONVERSION_CONST = 343 * 0.001 * 0.001 * 100 * 0.5;

  unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width;
  float cm;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Hold the trigger pin high 
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(MIN_TRIGGER_SIGNAL_DURATION);
  digitalWrite(TRIG_PIN, LOW);

  //The duration of the input pulse when ECHO_PIN is high
  pulse_width = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in centimetres 
  cm = pulse_width * PULSE_WIDTH_TO_CM_CONVERSION_CONST;

  // Print out results
  if ( cm > MAX_DISTANCE ) {
    Serial.println("Out of range");
    return -1;
  } else {
    Serial.print(cm);
    Serial.println(" cm");
  }

  delay(MIN_TIME_BETWEEN_MEASUREMENTS);

  return cm;
}

#endif
