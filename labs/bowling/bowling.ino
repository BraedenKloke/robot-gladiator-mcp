/**
Bowling lab.
*/

#define RIGHT_WHEEL_FORWARD 12 
#define RIGHT_WHEEL_REVERSE 11
#define LEFT_WHEEL_FORWARD 8 
#define LEFT_WHEEL_REVERSE 7
#define PROXIMITY_SENSOR 5 

void setup() {
  // Put your setup code here, to run once:

  // pinMode(13, OUTPUT);
  pinMode(RIGHT_WHEEL_FORWARD, OUTPUT);
  pinMode(RIGHT_WHEEL_REVERSE, OUTPUT);
  pinMode(LEFT_WHEEL_FORWARD, OUTPUT);
  pinMode(LEFT_WHEEL_REVERSE, OUTPUT);
  pinMode(PROXIMITY_SENSOR, INPUT);

}

void loop() {
  // Main loop where code runs repeatedly:

  // Spin right wheel
  digitalWrite(LEFT_WHEEL_FORWARD, true);
  
  // Read sensor
  if(digitalRead(PROXIMITY_SENSOR)){
    digitalWrite(LEFT_WHEEL_FORWARD, false);
  } 

  // Wait a little bit ... robots need rest and relaxation too!
  delay(500); 
}
