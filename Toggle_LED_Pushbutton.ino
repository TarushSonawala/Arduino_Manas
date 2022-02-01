const int button = 2;     // the number of the pushbutton pin
const int led =  8;      // the number of the LED pin
int ledState = LOW;     // the current state of LED
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  currentButtonState = digitalRead(button);
}
void loop() {
  lastButtonState = currentButtonState; // save the last state
  currentButtonState = digitalRead(button); // read new state
  delay(100);


  if (lastButtonState == HIGH && currentButtonState == LOW) {
    if (ledState == LOW) {
      digitalWrite(led, HIGH);
      ledState = HIGH;
    }
    else {
      digitalWrite(led, LOW);
      ledState = LOW;

    }
  }


}
