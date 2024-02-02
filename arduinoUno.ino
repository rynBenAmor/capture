#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);

  float humidity = 60;//dht.readHumidity();
  float temperature = 20;//dht.readTemperature();

  Serial.print("{\"humidité\":");
  Serial.print(humidity);
  Serial.print(", \"temperature\":");
  Serial.print(temperature);
  Serial.println("}");
}
