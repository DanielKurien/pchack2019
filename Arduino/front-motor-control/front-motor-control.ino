int In1 = 7; //Left
int In2 = 8;
int In3 = 4; //Right
int In4 = 3;
int ENA = 6;
int ENB = 5;

int SPEED = 210;

const int pingRight = 13;
const int echoRight = 12;
const int pingLeft = 11;
const int echoLeft = 10;

void setup(){
  Serial.begin(9600);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(pingLeft, OUTPUT);
  pinMode(pingRight, OUTPUT);
  pinMode(echoLeft, INPUT);
  pinMode(echoRight, INPUT);

  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3,HIGH);
  digitalWrite(In4, LOW);
  
//ENA 255 means high speed and 0 means low speed
 //analogWrite(ENB, SPEED);
}

void loop(){
   long rightCM = filterSensor(echoRight, pingRight);
   long leftCM = filterSensor(echoLeft, pingLeft);

   if(rightCM < 100) {
    analogWrite(ENB, 255);
    tone(2, 500, 200);
   }
   else {
    analogWrite(ENB, 0);
   }
   if(leftCM < 75) {
    analogWrite(ENA, 255);
    tone(2, 300, 200);
   }
   else {
    analogWrite(ENA, 0);
   }

   Serial.print("right ");
  long filtered;
   Serial.print(rightCM);
   Serial.print(" left ");
   Serial.print(leftCM);
   Serial.println();
}

long filterSensor(int echo, int ping) {
  long tests = 3;
  long filtered = 0;
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

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
