int ledVm = 7;
int ledVd = 4;
int ledAm = 6;

void setup() {
  //pinMode setar a variavel e o tipo de entrada
  pinMode(ledVm, OUTPUT);
  pinMode(ledVd, OUTPUT);
  pinMode(ledAm, OUTPUT);

}

void loop() {
  //a variavel e sua ação
  digitalWrite(ledVm, HIGH);
  delay(3000);
  //adicionar delay para a proxima ação
  digitalWrite(ledVm, LOW);


  digitalWrite(ledAm, HIGH);
  delay(3000);
  digitalWrite(ledAm, LOW);


  digitalWrite(ledVd, HIGH);
  delay(3000);
  digitalWrite(ledVd, LOW);
  }

}
