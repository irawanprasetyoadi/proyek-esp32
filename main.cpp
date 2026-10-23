#include <Arduino.h>
#include <DHT.h>

const int DHT_PIN = 4;
const int DHT_TYPE = DHT22;
DHT dht(DHT_PIN, DHT_TYPE);

const int LDR_PIN = 0;
const int LED_PIN = 1;
const float SUHU_BATAS = 30.0;

void setup() {
  Serial.begin(115200);
  dht.begin();
  analogReadResolution(12);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();
  int nilaiLDR = analogRead(LDR_PIN);

  // Cek suhu sebelum mengontrol LED (hindari NaN dari sensor)
  if (!isnan(suhu) && suhu >= SUHU_BATAS) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" C | Kelembapan: ");
  Serial.print(kelembapan);
  Serial.print(" % | Cahaya (LDR): ");
  Serial.println(nilaiLDR);

  delay(2000);
}
