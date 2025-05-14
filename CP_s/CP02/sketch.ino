#include<DHT.h>
#include<LiquidCrystal_I2C.h>
 
#define I2C_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_LINES 2
 
#define dhtPin 7
#define dhttype DHT22
 
int ledRed = 10;
int ledGreen = 11;
int ledYellow = 9;
 
const float GAMMA = 0.7;
const float RL10 = 50;
 
String luminosidade;
String temperatura;
String umidade;
 
DHT dht(dhtPin, dhttype);
 
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
 
void setup() {
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
 
void loop() {
  lcd.clear();
  int ldrVal = analogRead(A0);
  float voltage = ldrVal / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));
  int temp = dht.readTemperature();
  int umi = dht.readHumidity();
 
  if (lux > 300 ) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
 
    tone(8, 262, 3000);
 
 
    luminosidade = "CLARO";
  }
  else if (lux > 30) {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, LOW);
 
    luminosidade = "Meia Luz";
  }
  else {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, HIGH);
 
    luminosidade = "Escuro";
  }
 
  if (temp > 60) {
    temperatura = "Temp. ALTA";
  }
  else if (temp > 20) {
    temperatura = "Temp. OK";
  }
  else {
    temperatura = "Temp. BAIXA";
  }
 
  if (umi > 60) {
    umidade = "Umidade ALTA";
  }
  else if (umi > 20) {
    umidade = "Umidade OK";
  }
  else {
    umidade = "Umidade BAIXA";
  }
 
  lcd.setCursor(0, 0);
  lcd.print("Ambiente");
  lcd.setCursor(0, 1);
  lcd.print(luminosidade);
  delay(2000);
 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(temperatura);
  lcd.setCursor(0, 1);
  lcd.print("Temperatura: ");
  lcd.print(temp);
  delay(2000);
 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(umidade);
  lcd.setCursor(0, 1);
  lcd.print("Umidade: ");
  lcd.print(umi);
 
 
 
  Serial.println(lux);
  delay(1000);
}
 
 