#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ldrPin = A0;
int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin,OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  int lightVal = analogRead(ldrPin);
  Serial.println(lightVal);
  
  if (lightVal > 512){
    tone(buzzerPin , 200);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Interference");
    lcd.setCursor(0,1);
    lcd.print("Detected");
  }
  
  else{
    noTone(buzzerPin);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No Interference");
    lcd.setCursor(0,1);
    lcd.print("Detected");
  }
  
  delay(100);
}
