#include<DHT.h>
#define dhtPin 2
#define dhttype DHT11
int ledV = 7;
int ledA = 6;
int ledVd = 5;

DHT dht(dhtPin, dhttype);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledVd, OUTPUT);
}

void loop() {
  int temp = dht.readTemperature();
  int umi = dht.readHumidity();

  Serial.println("Temperatura: " + String(temp));
  Serial.println("Umidade: " + String(umi));
  delay (3000);

  if (umi > 70){
    digitalWrite(ledV, HIGH);
    delay(2000);
    digitalWrite(ledV, LOW);
  }
 else if (umi < 60){
    digitalWrite(ledVd, HIGH);
    delay(2000);
    digitalWrite(ledVd, LOW);
 }
  else {
    digitalWrite(ledA, HIGH);
    delay(2000);
    digitalWrite(ledA, LOW);
  }
}
