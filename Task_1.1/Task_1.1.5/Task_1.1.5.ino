int soundPin = 4;
int soundVal = LOW;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN , OUTPUT);
  pinMode(soundPin , INPUT);
  Serial.println("Begin detection");
}

void loop() {
  soundVal = digitalRead(soundPin);
  if(soundVal == HIGH){
    digitalWrite(LED_BUILTIN , HIGH);
    Serial.println("Sound detected");
    delay(2000);
    digitalWrite(LED_BUILTIN , LOW);
  }
  delay(50);
}
