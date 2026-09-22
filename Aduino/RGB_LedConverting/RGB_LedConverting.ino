#define RED 10
#define GREEN 9
#define BLUE 3

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void color(int r, int g, int b) {
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}

void loop() {
  for (int i = 0; i < 255; i++) { color(255, i, 0); delay(10); }    // R -> Y
  for (int i = 255; i > 0; i--) { color(i, 255, 0); delay(10); }    // Y -> G

  for (int i = 0; i < 255; i++) { color(0, 255, i); delay(10); }    // G -> C
  for (int i = 255; i > 0; i--) { color(0, i, 255); delay(10); }    // C -> B

  for (int i = 0; i < 255; i++) { color(i, 0, 255); delay(10); }    // B -> M
  for (int i = 255; i > 0; i--) { color(255, 0, i); delay(10); }    // M -> R
}
