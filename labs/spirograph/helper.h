#ifndef __HELPER_H_
#define __HELPER_H_

#define B1A 12 // Right wheel forward
#define B1B 11 // Right wheel reverse
#define A1A 8 // Left wheel forward
#define A1B 7 // Left wheel reverse
#define PROXI 5 // Sensor

void initialize_pins() {
  pinMode(B1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  pinMode(PROXI, INPUT);
}

void forward() {
  digitalWrite(B1A, true);
  digitalWrite(B1B, false);
  digitalWrite(A1A, true);
  digitalWrite(A1B, false);
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

void stop() {
  digitalWrite(B1A, false);
  digitalWrite(B1B, false);
  digitalWrite(A1A, false);
  digitalWrite(A1B, false);
}

#endif
