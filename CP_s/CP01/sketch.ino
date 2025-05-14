int ledRed = 10;
int ledGreen = 11;
int ledYellow = 9;

const float GAMMA = 0.7;
const float RL10 = 50;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  int ldrVal = analogRead(A0); 
  float voltage = ldrVal / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

  if (lux > 300) {             
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, LOW);  
    digitalWrite(ledGreen, LOW);

    tone(8, 262, 3000);
  }
  else if(lux > 30){
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, HIGH);  
    digitalWrite(ledGreen, LOW);
  }
  else {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);  
    digitalWrite(ledGreen, HIGH);   
  }
  Serial.println(lux);      
  delay(1000);
}
