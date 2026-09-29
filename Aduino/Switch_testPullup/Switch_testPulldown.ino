void setup() {
  pinMode(12, INPUT);

  Serial.begin(9600);
  while (!Serial);

}

void loop() {
  int nSw = digitalRead(12);

  if (nSw == LOW) { 
    Serial.println("LED ON");
  } else {
    Serial.println("LED OFF");
    delay(1000);
  }
}
