#include <Arduino.h>

#define vooruit 7
#define links 8
#define achteruit 12
#define rechts 2
#define snelheidmeneer 0


char snelheid;



void setup() {
  pinMode(vooruit, INPUT);
  pinMode(links, INPUT);
  pinMode(achteruit, INPUT);
  pinMode(rechts, INPUT);
  pinMode(snelheidmeneer, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void snelheidmeten() {
  snelheid = map(analogRead(snelheidmeneer), 0, 1023, 0, 255);
}

void vooruitgaan() {
  snelheidmeten();
  digitalWrite(5, LOW);
  analogWrite(6, snelheid);
  digitalWrite(3, LOW);
  analogWrite(9, snelheid);
}

void linksgaan() {
  snelheidmeten();
  digitalWrite(5, LOW);
  analogWrite(6, snelheid);
  digitalWrite(3, HIGH);
  analogWrite(9, 255-snelheid);
}

void achteruitgaan() {
  snelheidmeten();
  digitalWrite(5, HIGH);
  analogWrite(6, 255-snelheid);
  digitalWrite(3, HIGH);
  analogWrite(9, 255-snelheid);
}

void rechtsgaan() {
  snelheidmeten();
  digitalWrite(5, HIGH);
  analogWrite(6, 255-snelheid);
  digitalWrite(3, LOW);
  analogWrite(9, snelheid);
}


void loop() {
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);

  while (digitalRead(vooruit)) {
    vooruitgaan();
  }

  while (digitalRead(links)) {
    linksgaan();
  }

  while (digitalRead(achteruit)) {
    achteruitgaan();
  }

  while (digitalRead(rechts)) {
    rechtsgaan();
  }
}