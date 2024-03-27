#include <Arduino.h>

#define vooruit 7
#define links 8
#define achteruit 12
#define rechts 2


void setup() {
  pinMode(vooruit, INPUT);
  pinMode(links, INPUT);
  pinMode(achteruit, INPUT);
  pinMode(rechts, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void vooruitgaan() {
  digitalWrite(5, LOW);
  analogWrite(6, 64);
  digitalWrite(3, LOW);
  analogWrite(9, 64);
}

void linksgaan() {
  digitalWrite(5, LOW);
  analogWrite(6, 64);
  digitalWrite(3, HIGH);
  analogWrite(9, 64);
}

void achteruitgaan() {
  digitalWrite(5, HIGH);
  analogWrite(6, 128);
  digitalWrite(3, HIGH);
  analogWrite(9, 64);
}

void rechtsgaan() {
  digitalWrite(5, HIGH);
  analogWrite(6, 64);
  digitalWrite(3, LOW);
  analogWrite(9, 64);
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