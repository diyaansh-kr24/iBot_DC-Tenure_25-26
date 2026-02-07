const int buttonPin = 2;
const int ledPin = 13;

bool ledState = LOW;
bool lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (lastButtonState == LOW && buttonState == HIGH) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    delay(50);
  }

  lastButtonState = buttonState;
}
