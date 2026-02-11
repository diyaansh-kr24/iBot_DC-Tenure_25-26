#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

const int soundPin = A0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  pinMode(soundPin, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.begin(9600);
}

void loop() {
  int soundVal = analogRead(soundPin);
  Serial.println(soundVal);

  int mappedVal = map(soundVal, 450, 700 , 0, 55);

  display.clearDisplay();

  display.drawLine(64, 0, 64, 63, WHITE);
  display.fillRect(64 - mappedVal, 21, mappedVal * 2, 22, WHITE);

  display.display();
  delay(20);
}