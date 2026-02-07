const int pirPin = 2;
const int ledPin = 12;

int lastState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  int currentState = digitalRead(pirPin);

  if (currentState == HIGH && lastState == LOW) {
    Serial.println("Motion detected");
    digitalWrite(ledPin, HIGH);
  }

  if (currentState == LOW && lastState == HIGH) {
    Serial.println("Motion stopped");
    digitalWrite(ledPin, LOW);
  }
  lastState = currentState;
}
