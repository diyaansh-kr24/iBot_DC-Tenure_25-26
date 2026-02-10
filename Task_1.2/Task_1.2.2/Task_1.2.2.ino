#include <LiquidCrystal.h>
LiquidCrystal mylcd(12,11,10,9,8,7);

void setup() {
  mylcd.begin(16,2);
  mylcd.setCursor(0,0);
  mylcd.print("Hello World");
  mylcd.setCursor(0,1);
  mylcd.print("Diyaansh");
}

void loop() {
}
