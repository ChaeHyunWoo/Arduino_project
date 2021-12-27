#include<Servo.h>
Servo servo;
const int TrigPin = 8;
const int EchoPin = 9;
long Duration = 0;
int value = 0;

void setup() {
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  servo.attach(3);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  digitalWrite(TrigPin, HIGH);
  delay(10);
  digitalWrite(TrigPin, LOW);

  duration = pulseIn(EchoPin, HIGH);

  distance = duration/29/2;

  Serial.print(distance);
  Serial.print("cm");
  Serial.println();

  delay(100);

  if (distance < 10)
  {
    servo.write(90);
    delay(3000);
  }
  else if (distance > 40)
  {
    servo.write(0);
    delay(1000);
  }
}
