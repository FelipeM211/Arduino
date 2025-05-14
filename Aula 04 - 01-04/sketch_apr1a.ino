#include<DHT.h>
#define dhtPin 2
#define dhttype DHT11

DHT dht(dhtPin, dhttype);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  int temp = dht.readTemperature();
  int umi = dht.readHumidity();

  Serial.println("Temperatura: " + String(temp));
  Serial.println("Umidade: " + String(umi));
  delay (1000);
}
