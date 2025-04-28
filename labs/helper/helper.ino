#include "helper.h"

float LINEAR_SPEED, ANGULAR_SPEED;
int dutyCycle = 50;
int count = 10;
bool flag = true;

void setup() {
  Serial.begin(9600);

  initializePins();

  LINEAR_SPEED = 1;
  ANGULAR_SPEED = 1;

  Serial.begin(9600);
}

void loop() {
  // Obstacle Detection Tests
  // if (isObstacleDetected()) {
  //   Serial.println("Infrared Sensor : YES");
  // } else {
  //   Serial.println("Infrared Sensor : NO");
  // }

  // measureDistance();
  count++;
  if(count == 100) {
    count = 0;
    if(flag) {
      dutyCycle += 10;
    } else {
      dutyCycle -= 10;
    }

    if(dutyCycle == 100 || dutyCycle == 0) {
      flag = !flag;
    }
  }


  float upDuty = (float)dutyCycle / 100.0;
  float downDuty = 1.0 - upDuty;

  unsigned int upCycle = (unsigned int)(10000 * upDuty);
  unsigned int downCycle = (unsigned int)(10000 * downDuty);

  // Serial.print(upDuty);
  // Serial.print(",");
  // Serial.print(downDuty);
  // Serial.print(",");
  // Serial.print(upCycle);
  // Serial.print(",");
  // Serial.print(downCycle);
  // Serial.println("");

  forward();
  delayMicroseconds(upCycle);
  stop();
  delayMicroseconds(downCycle);
  
}
