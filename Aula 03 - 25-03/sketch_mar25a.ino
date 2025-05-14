#define trigger 7
#define echo 8
// #define não oucupa espaço na memória e não pode ser alternado
int dist = 0;
int ledV = 3;
int ledA = 5;
int ledVer = 6;


void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(ledV, OUTPUT);
  pinMode(ledVer, OUTPUT);
  pinMode(ledA, OUTPUT);
  Serial.begin(9600);
  }

void loop() {
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  dist = pulseIn(echo, HIGH);
  dist = dist / 58;
  Serial.println("Distancia: " + String(dist));
  delay(2000);

  if(dist < 10){
    digitalWrite(ledV, HIGH);
    delay(2000);
    digitalWrite(ledV, LOW);
  }else if(dist > 35){
    digitalWrite(ledVer, HIGH);
    delay(2000);
    digitalWrite(ledVer, LOW);
  }else{
    digitalWrite(ledA, HIGH);
    delay(2000);
    digitalWrite(ledA, LOW);
  }
}
