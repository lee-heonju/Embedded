int BUTTON = 12;

int LED1 = 3;
int LED2 = 5;
int LED3 = 7;
int LED4 = 9;
int LED5 = 11;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {

  if (digitalRead(BUTTON) == LOW) {

    digitalWrite(LED1, HIGH);
    delay(300);

    digitalWrite(LED2, HIGH);
    delay(300);

    digitalWrite(LED3, HIGH);
    delay(300);

    digitalWrite(LED4, HIGH);
    delay(300);

    digitalWrite(LED5, HIGH);
    delay(300);

    digitalWrite(LED5, LOW);
    delay(300);

    digitalWrite(LED4, LOW);
    delay(300);

    digitalWrite(LED3, LOW);
    delay(300);

    digitalWrite(LED2, LOW);
    delay(300);

    digitalWrite(LED1, LOW);
    delay(300);
  }
}