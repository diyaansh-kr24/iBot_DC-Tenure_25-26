const int buzzerPin = 12;
const int frequency = 100;
void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Start Buzzer");
}

void loop() {
  tone(buzzerPin, frequency);
}
