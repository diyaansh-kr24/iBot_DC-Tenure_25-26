const int LED_PIN = 11;
const int time = 10;
void setup(){
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  for(int brightness=0; brightness <= 255; brightness +=5){
      analogWrite(LED_PIN, brightness);
  		delay(time);
  }
	
   for(int brightness=255; brightness >= 0; brightness -=5){
      analogWrite(LED_PIN, brightness);
  		delay(time);
   }
}