int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int led1State = LOW;
int led2State = LOW;
int led3State = LOW;
int led4State = LOW;
int pot = A5;
int readValue;
int writeValue;
int button = 4;
int button_Count = 0;
int button_Value;
void setup() {
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(button, INPUT);
  button_Value = digitalRead(button);
}

void loop() {
  button_Value = digitalRead(button);//reads push button state
  delay(100);

  if (button_Value == HIGH) {
    button_Count = button_Count + 1;
    Serial.println(button_Count);
  }

  if (button_Count == 1) {

    readValue = analogRead(pot);
    writeValue = map(readValue, 0, 1023, 0, 255);// map(value, fromLow, fromHigh, toLow, toHigh)
    digitalWrite(led1, HIGH);    // turn on LED1
    delay(writeValue);
    digitalWrite(led2, HIGH);    // turn on LED2
    delay(writeValue);
    digitalWrite(led3, HIGH);    // turn on LED3
    delay(writeValue);
    digitalWrite(led4, HIGH);    // turn on LED4
    delay(writeValue);
    digitalWrite(led1, LOW);    // turn off LED1
    delay(writeValue);
    digitalWrite(led2, LOW);    // turn off LED2
    delay(writeValue);
    digitalWrite(led3, LOW);    // turn off LED3
    delay(writeValue);
    digitalWrite(led4, LOW);    // turn off LED4
    button_Value = digitalRead(button);//reads push button state
    delay(500);
    if (button_Value == HIGH) {
      button_Count = 2;
      Serial.println(button_Count);
    }

  }
  if (button_Count == 2) {
    digitalWrite(led1, LOW);    // turn off LED1
    digitalWrite(led2, LOW);    // turn off LED2
    digitalWrite(led3, LOW);    // turn off LED3
    digitalWrite(led4, LOW);    // turn off LED4
    button_Count = 0;
    Serial.println(button_Count);
  }



}
