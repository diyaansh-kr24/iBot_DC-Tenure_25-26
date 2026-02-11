#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT  64

const int upPin = 3;
const int downPin = 4;
const int leftPin = 5;
const int rightPin = 6;

bool upLastButtonState = HIGH;
bool downLastButtonState = HIGH;
bool leftLastButtonState = HIGH;
bool rightLastButtonState = HIGH;

int posX = 56;
int posY = 24;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  pinMode(upPin, INPUT_PULLUP);
  pinMode(downPin, INPUT_PULLUP);
  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  bool upButtonState = digitalRead(upPin);
  bool downButtonState = digitalRead(downPin);
  bool leftButtonState = digitalRead(leftPin);
  bool rightButtonState = digitalRead(rightPin);

  if (upButtonState == LOW && upLastButtonState == HIGH) {
    Serial.println("Up");
    if(posY >= 8){
      posY -= 8;
    } else {
      posY = 63 - (7-posY);
    }
  }

  if (downButtonState == LOW && downLastButtonState == HIGH) {
    Serial.println("Down");
    if(posY <= 55){
      posY += 8;
    } else {
      posY = 63 - (posY + 7);
    }
  }

  if (leftButtonState == LOW && leftLastButtonState == HIGH) {
    Serial.println("Left");
    if(posX >= 8){
      posX -= 8;
    } else {
      posX = 127 - (7-posX);
    }
  }

  if (rightButtonState == LOW && rightLastButtonState == HIGH) {
    Serial.println("Right");
    if(posX <= 119){
      posX += 8;
    } else {
      posX = 127 - (posX + 7);
    }
  }

  display.clearDisplay();

  for(int i = 0 ; i<=127; i+=8){
    display.drawLine(i, 0, i , 63, WHITE);
  }
  for(int i = 0 ; i<=63; i+=8){
    display.drawLine(0, i, 127 , i, WHITE);
  }
  display.drawLine(127, 0, 127 , 63, WHITE);
  display.drawLine(0, 63, 127 , 63, WHITE);

  display.fillRect(posX, posY, 8, 8, WHITE);
  display.display();

  upLastButtonState = upButtonState;
  downLastButtonState = downButtonState;
  leftLastButtonState = leftButtonState;
  rightLastButtonState = rightButtonState;
  
  delay(10);
}