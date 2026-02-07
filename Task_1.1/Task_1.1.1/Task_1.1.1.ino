const int irPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int irValue = analogRead(irPin);
  Serial.print("IR Reading: ");
  Serial.println(irValue);
  delay(100);
}
