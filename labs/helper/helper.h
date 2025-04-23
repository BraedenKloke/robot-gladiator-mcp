#ifndef __HELPER_H_
#define __HELPER_H_

#define LINEAR_SPEED 1 // metres / second

#define B1A 12 // Right wheel forward
#define B1B 11 // Right wheel reverse
#define A1A 8 // Left wheel forward
#define A1B 7 // Left wheel reverse
#define PROXI 5 // Sensor


/*
 * Function: initializePins
 * ========================
 * Initialize input and output pins.
 */
void initializePins() {
  pinMode(B1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  pinMode(PROXI, INPUT);
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

void left() {
  digitalWrite(B1A, false);
  digitalWrite(B1B, true);
  digitalWrite(A1A, true);
  digitalWrite(A1B, false);
}

void reverse() {
  digitalWrite(B1A, false);
  digitalWrite(B1B, true);
  digitalWrite(A1A, false);
  digitalWrite(A1B, true);
}

#endif
