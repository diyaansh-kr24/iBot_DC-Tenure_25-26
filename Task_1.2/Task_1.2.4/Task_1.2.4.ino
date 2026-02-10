#include <Servo.h>
Servo servo;

void sweep(){
  for (int angle = 0; angle<=180; angle++){
    servo.write(angle);
    delay(10);
  }
}

void reverseSweep(){
  for (int angle = 180; angle>=0; angle--){
    servo.write(angle);
    delay(10);
  }
}

void setup() {
  servo.attach(9);
}

void loop() {
  sweep();
  reverseSweep();
}
