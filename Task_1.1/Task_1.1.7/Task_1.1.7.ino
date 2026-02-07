#include <DHT.h>
const int DHT11_pin=4;

float Humidity,Temperature;
DHT my_DHT11(DHT11_pin,DHT11);

void setup() {
  Serial.begin(9600);
  my_DHT11.begin();
}

void loop() {

 Temperature = my_DHT11.readTemperature();
 Humidity = my_DHT11.readHumidity();

  if(isnan(Humidity) || isnan(Temperature))
  {
    Serial.println("Could not take reading");
  }
  else
  {
    Serial.print("Temperature: ");
    Serial.print(Temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(Humidity);
    Serial.println(" %");
  }
 delay(1000);
}