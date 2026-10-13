int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int LED5 = 9;
int BUTTON = 2;

int COUNT = 0;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  allOff();

  while (digitalRead(BUTTON) == LOW) {
    delay(10);
  }
}

void loop() {
  while (digitalRead(BUTTON) == HIGH) {
    delay(5);
  }

  delay(30);

  if (digitalRead(BUTTON) != LOW) {
    return;
  }

  COUNT++;

  while (digitalRead(BUTTON) == LOW) {
    delay(5);
  }

  delay(30);

  int currentCount = COUNT % 4;

  while (true) {
    allOff();

    if (currentCount == 1) {
      int leds[] = {LED1, LED2, LED3, LED4, LED5};

      for (int i = 0; i < 5; i++) {
        digitalWrite(leds[i], LOW);
        if (waitWithCheck(500)) return;
        digitalWrite(leds[i], HIGH);
      }
    }
    else if (currentCount == 2) {
      int leds[] = {LED5, LED4, LED3, LED2, LED1};

      for (int i = 0; i < 5; i++) {
        digitalWrite(leds[i], LOW);
        if (waitWithCheck(500)) return;
        digitalWrite(leds[i], HIGH);
      }
    }
    else if (currentCount == 3) {
      int leds[] = {LED1, LED2, LED3, LED4, LED5};

      for (int i = 0; i < 5; i++) {
        digitalWrite(leds[i], LOW);
        if (waitWithCheck(500)) return;
      }
    }
    else {
      int leds[] = {LED5, LED4, LED3, LED2, LED1};

      for (int i = 0; i < 5; i++) {
        digitalWrite(leds[i], LOW);
        if (waitWithCheck(500)) return;
      }
    }
  }
}

bool waitWithCheck(int ms) {
  for (int t = 0; t < ms; t += 10) {
    if (digitalRead(BUTTON) == LOW) {
      return true;
    }
    delay(10);
  }
  return false;
}

void allOff() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
}