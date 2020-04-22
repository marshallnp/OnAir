const int Led1 = 8;
const int Led2 = 9;
const int Led3 = 10;
const int Button = 7;

int LedState = HIGH;
int ButtonCurrent;
int ButtonPrevious = LOW;
int ButtonCounter = 0;
int LedCounter = 0;


void setup() {
  Serial.begin(9600);
  pinMode(Button, INPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
}

void loop() {
  Serial.println(ButtonCounter);
  ButtonCurrent = digitalRead(Button);

  if (LedCounter > 100) {
    LedState = HIGH;
  }
  else {
    LedState = LOW;
  }

  
  if (LedCounter > 200) {
    LedCounter = 0;
  }

  if (ButtonCurrent == HIGH && ButtonPrevious == LOW) {
    ButtonCounter = ButtonCounter + 1;
//   if (LedState == HIGH) { LedState = LOW; }
//   else { LedState = HIGH; }
  }

  if (ButtonCounter > 8) {
    ButtonCounter = 0;
  }

  if (ButtonCounter == 0) {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
  }

  if (ButtonCounter == 1) {
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
  }

  if (ButtonCounter == 2) {
    digitalWrite(Led1, LedState);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
  }

  if (ButtonCounter == 3) {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, LOW);
  }

  if (ButtonCounter == 4) {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LedState);
    digitalWrite(Led3, LOW);
  }

  if (ButtonCounter == 5) {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, HIGH);
  }

  if (ButtonCounter == 6) {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LedState);
  }

  if (ButtonCounter == 7) {
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, HIGH);
  }

  if (ButtonCounter == 8) {
    digitalWrite(Led1, LedState);
    digitalWrite(Led2, LedState);
    digitalWrite(Led3, LedState);
  }

  LedCounter = LedCounter + 1;


  ButtonPrevious = ButtonCurrent;
}
