#include <Servo.h>

Servo servoOne;
const int pingPin = 13; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor
const int motorPin = 7;

void setup() {
  Serial.begin(9600); // Starting Serial Terminal
  servoOne.attach(7);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long filterSensor(int echo, int ping) {
  long filtered;
  long tests = 3;
  for(int i = 0; i < tests; i++) {
   long latest = readUltrasonic(echo, ping);
   if(latest < 1) {
    i--;
   }
   else {
    filtered += latest;
   }
  }
  return filtered/tests;
}

long readUltrasonic(int echo, int ping) {
   digitalWrite(ping, LOW);
   delayMicroseconds(2);
   digitalWrite(ping, HIGH);
   delayMicroseconds(10);
   digitalWrite(ping, LOW);
   long duration = pulseIn(echo, HIGH);
   long cm = microsecondsToCentimeters(duration);
   return cm;
}

void loop() {
   long cm = filterSensor(echoPin, pingPin);
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   if(cm < 50) {
    servoOne.write(100);

   }
   else {
    servoOne.write(1);
    
   }
   //delay(100);
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
