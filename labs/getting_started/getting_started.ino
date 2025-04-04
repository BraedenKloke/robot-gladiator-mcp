/**
Getting started lab.

Spins the right wheel when the robot's sensor detects an object.
*/

#define B1A 12 // Right wheel forward
#define B1B 11 // Right wheel reverse
#define A1A 8 // Left wheel forward
#define A1B 7 // Left wheel reverse
#define PROXI 5 // Sensor

void setup() {
  // Put your setup code here, to run once:

  // pinMode(13, OUTPUT);
  pinMode(B1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  pinMode(PROXI, INPUT);

}

void loop() {
  // Main loop where code runs repeatedly:

  // Spin right wheel
  digitalWrite(A1A, true);
  
  // Read sensor
  if(digitalRead(PROXI)){
    digitalWrite(A1A, false);
  } 

  // Wait a little bit ... robots need rest and relaxation too!
  delay(500); 
}
