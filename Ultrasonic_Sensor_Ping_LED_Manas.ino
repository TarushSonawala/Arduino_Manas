#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
float led1 = 8;
float led2 = 9;
float led3 = 10;
float led4 = 11;
float led5 = 12;
float led6 = 13;
float duration; // variable for the duration of sound wave travel
float distance; // variable for the distance measurement
long microsecondsToCentimeters;

const int pingPin = 6;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if ( distance > 0) {
    digitalWrite(led1, HIGH);//turns on led1
  }
  else {
    digitalWrite(led1, LOW);
  }
  if (distance >= 54 ) {
    digitalWrite(led2, HIGH);//turns on led2

  }
  else {
    digitalWrite(led2, LOW);
  }
  if (distance >= 108) {
    digitalWrite(led3, HIGH);//turns on led3
  }
  else {
    digitalWrite(led3, LOW);
  }
  if (distance >= 162) {
    digitalWrite(led4, HIGH);//turns on led4
  }
  else {
    digitalWrite(led4, LOW);
  }
  if (distance >= 216) {
    digitalWrite(led5, HIGH);//turns on led5
  }
  else {
    digitalWrite(led5, LOW);
  }
  if (distance >= 270) {
    digitalWrite(led6, HIGH);//turns on led6
  }
  else {
    digitalWrite(led6, LOW);
  }
}
