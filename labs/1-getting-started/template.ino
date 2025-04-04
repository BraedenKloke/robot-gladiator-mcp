
bool flag = false;

#define B1A 12
#define B1B 11
#define A1A 8
#define A1B 7
#define PROXI 5

void setup() {
  // put your setup code here, to run once:

  // pinMode(13, OUTPUT);
  pinMode(B1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  pinMode(PROXI, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(PROXI)){
    digitalWrite(B1A, true);
    digitalWrite(B1B, false);
    digitalWrite(A1A, true);
    digitalWrite(A1B, false);
  } else {
    digitalWrite(B1A, false);
    digitalWrite(B1B, true);
    digitalWrite(A1A, true);
    digitalWrite(A1B, false);
  }
  delay(500);

}
