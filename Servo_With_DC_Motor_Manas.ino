#include <Servo.h> // Include the Servo library 
int servoPin = 9;
int motorPin = 5;
int button1 = 2;//switch for servo
int button2 = 4; //switch for motor
int enable = 10; //enable 1&2 pin
int input1 = 11; //input 1
int input2 = 6; //input 2
boolean reverse; //in which direction motor shaft is rotating
//it gives value in True or False
int motorSpeed;
int buttonState1;
int buttonState2;
int pot = A0;
int readValue = 0;
int writeValue;
Servo servo1;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(enable, OUTPUT);
  Serial.begin(9600);
  servo1.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
}

void loop() {

  if (digitalRead(button1) == LOW) {
    digitalWrite(enable, LOW);
    readValue = analogRead(pot);
    writeValue = map(readValue, 0, 1023, 0, 30); //map(value, fromLow, fromHigh, toLow, toHigh)
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(writeValue);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(writeValue);                       // waits 15ms for the servo to reach the position
    }
  }
  else {

    reverse = digitalRead(button2);
    readValue = analogRead(pot);
    motorSpeed = map(readValue, 0, 1023, 0, 255);// map(value, fromLow, fromHigh, toLow, toHigh)
    Serial.println(motorSpeed);
    analogWrite(enable, motorSpeed);
    digitalWrite(input1, !reverse);
    digitalWrite(input2, reverse);
  }
  delay(10);
}
