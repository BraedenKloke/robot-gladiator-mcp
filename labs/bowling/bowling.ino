/**
Bowling lab.
*/

#define RIGHT_WHEEL_FORWARD 12 
#define RIGHT_WHEEL_REVERSE 11
#define LEFT_WHEEL_FORWARD 8 
#define LEFT_WHEEL_REVERSE 7
#define PROXIMITY_SENSOR 5 

bool objectDetected;

void setup() {
  // Put your setup code here, to run once:

  // pinMode(13, OUTPUT);
  pinMode(RIGHT_WHEEL_FORWARD, OUTPUT);
  pinMode(RIGHT_WHEEL_REVERSE, OUTPUT);
  pinMode(LEFT_WHEEL_FORWARD, OUTPUT);
  pinMode(LEFT_WHEEL_REVERSE, OUTPUT);
  pinMode(PROXIMITY_SENSOR, INPUT);

  objectDetected = false;

}

void loop() {
  // Main loop where code runs repeatedly:
  
  objectDetected = digitalRead(PROXIMITY_SENSOR) == false;
  if(objectDetected){
    // Turn right
    digitalWrite(LEFT_WHEEL_FORWARD, false);
    delay(500); 
  } 

  // Move forward
  digitalWrite(LEFT_WHEEL_FORWARD, true);
  digitalWrite(RIGHT_WHEEL_FORWARD, true);
}
