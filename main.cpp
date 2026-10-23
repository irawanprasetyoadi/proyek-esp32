#include <Arduino.h>
#include <DHT.h>

const int DHT_PIN = 4;
const int DHT_TYPE = DHT22;
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();

  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" C | Kelembapan: ");
  Serial.print(kelembapan);
  Serial.println(" %");

  delay(2000);
}
