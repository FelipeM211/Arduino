int led = 7;
int x = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  for(x=0; x < 3; x++){//Letra S
digitalWrite(led, HIGH);
delay(500);
digitalWrite(led, LOW);
delay(500);
}

delay(1000);

  for(x=0; x < 3; x++){ //Letra O
digitalWrite(led, HIGH);
delay(1000);
digitalWrite(led, LOW);
delay(500);
}

delay(1000);

  for(x=0; x < 3; x++){ //Letra S
digitalWrite(led, HIGH);
delay(500);
digitalWrite(led, LOW);
delay(500);
}
delay(1000);
}