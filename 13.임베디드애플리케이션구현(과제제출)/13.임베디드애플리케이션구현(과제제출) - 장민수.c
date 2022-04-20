// C++ code
//
int PIN_LED7 = 7;
int PIN_LED8 = 8;
int PIN_LED9 = 9;
int PIN_LED10 = 10;

int PIN_TRIGER = 4;
int PIN_ECHO = 3;

void setup()
{
  pinMode(PIN_LED7, OUTPUT);
  pinMode(PIN_LED8, OUTPUT);
  pinMode(PIN_LED9, OUTPUT);
  pinMode(PIN_LED10, OUTPUT);
  
  pinMode(PIN_TRIGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  int distance = 0;
  
  digitalWrite(PIN_TRIGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGER, LOW);
  
  distance = pulseIn(PIN_ECHO, HIGH);
  int cm = distance / 57;
  
  // Serial.println(cm);
  
  if (cm >= 240) {
    digitalWrite(PIN_LED7, LOW);
    digitalWrite(PIN_LED8, LOW);
    digitalWrite(PIN_LED9, LOW);
    digitalWrite(PIN_LED10, LOW);
  } else if (cm < 240 && cm >= 190) {
    digitalWrite(PIN_LED7, LOW);
  	digitalWrite(PIN_LED8, LOW);
    digitalWrite(PIN_LED9, LOW);
    digitalWrite(PIN_LED10, HIGH);
  } else if (cm < 190 && cm >= 140) {
    digitalWrite(PIN_LED7, LOW);
    digitalWrite(PIN_LED8, LOW);
    digitalWrite(PIN_LED9, HIGH);
    digitalWrite(PIN_LED10, HIGH);
  } else if (cm < 140 && cm >= 90) {
    digitalWrite(PIN_LED7, LOW);
    digitalWrite(PIN_LED8, HIGH);
    digitalWrite(PIN_LED9, HIGH);
    digitalWrite(PIN_LED10, HIGH);
  } else {
    digitalWrite(PIN_LED7, HIGH);
    digitalWrite(PIN_LED8, HIGH);
    digitalWrite(PIN_LED9, HIGH);
    digitalWrite(PIN_LED10, HIGH);
  }
}