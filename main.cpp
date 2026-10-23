#include <Arduino.h>
#include <DHT.h>

const int DHT_PIN = 4;
const int DHT_TYPE = DHT22;
DHT dht(DHT_PIN, DHT_TYPE);

const int LDR_PIN = 34;  // Pin ADC untuk LDR (ESP32)

void setup() {
  Serial.begin(115200);
  dht.begin();
  analogReadResolution(12);  // Resolusi ADC 0-4095
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();
  int nilaiLDR = analogRead(LDR_PIN);

  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" C | Kelembapan: ");
  Serial.print(kelembapan);
  Serial.print(" % | Cahaya (LDR): ");
  Serial.println(nilaiLDR);

  delay(2000);
}
