#include <Chrono.h>

Chrono ledChrono;

void switchLed(int pin, int msOn, int msOff, Chrono& c);

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  switchLed(13, 500, 3000, ledChrono);
}

void switchLed(int pin, int msOn, int msOff, Chrono& c){
  if(digitalRead(pin)==HIGH && c.hasPassed(msOn)){
      digitalWrite(pin,!digitalRead(pin));
      c.restart();
  }else if(digitalRead(pin)==LOW && c.hasPassed(msOff)){
      digitalWrite(pin,!digitalRead(pin));
      c.restart();
  }
}
