#include <Arduino.h>

#include <Arduino.h>
#include "motors.h"

const int IN1 = 6;
const int IN2 = 7;
const int IN3 = 8;
const int IN4 = 9;
const int SLEEP = 5;

void oprireMotoare() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void initializareMotoare() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(SLEEP, OUTPUT);

    oprireMotoare();

    digitalWrite(SLEEP, HIGH);
    delay(100);
}

void mersInainte() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
}

void mersInapoi() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
}

void virajStanga() {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void virajDreapta() {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void testMotoare() {

    // FATA
    mersInainte();
    delay(2000);
    oprireMotoare();
    delay(1000);

    // SPATE
    mersInapoi();
    delay(2000);
    oprireMotoare();
    delay(1000);

    // STANGA
    virajStanga();
    delay(200);
    oprireMotoare();
    delay(1000);

    // DREAPTA
    virajDreapta();
    delay(200);
    oprireMotoare();
    delay(2000);
}
