#define RED 10
#define GREEN 9
#define BLUE 3

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}

int nzRGB[3]={0,0,0};
int nLoop = 0;

void loop() {
    
    if (Serial.available() > 0) {
    String strValue = Serial.readString();
    Serial.print("Read : ");
    int nValue = strValue.toInt();
    Serial.println(nValue);

  if(nLoop%3==0)
    Serial.print('R');
  else if(nLoop%3==1)
    Serial.print('G');
  else
    Serial.print('B');

  Serial.println(nValue);

  nzRGB[nLoop%3]=nValue;

  nLoop++;
  if(nLoop>=100000)
    nLoop=0;

  if (nLoop % 3 == 0) {
      analogWrite(RED, nzRGB[0]);
      analogWrite(GREEN, nzRGB[1]);
      analogWrite(BLUE, nzRGB[2]);
  }
}
}