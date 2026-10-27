
#include <Arduino.h>
#include "motors.h"
#include "config.h"

void oprireMotoare() {
    digitalWrite(MOTOR_DRIVE_IN1, LOW);
    digitalWrite(MOTOR_DRIVE_IN2, LOW);
    digitalWrite(MOTOR_STEER_IN1, LOW);
    digitalWrite(MOTOR_STEER_IN2, LOW);
}

void initializareMotoare() {
    pinMode(MOTOR_ENABLE, OUTPUT);
    pinMode(MOTOR_DRIVE_IN1, OUTPUT);
    pinMode(MOTOR_DRIVE_IN2, OUTPUT);
    pinMode(MOTOR_STEER_IN1, OUTPUT);
    pinMode(MOTOR_STEER_IN2, OUTPUT);

    oprireMotoare();
    digitalWrite(MOTOR_ENABLE, HIGH);
    delay(100);
}

void mersInainte() {
    digitalWrite(MOTOR_DRIVE_IN1, HIGH);
    digitalWrite(MOTOR_DRIVE_IN2, LOW);
}

void mersInapoi() {
    digitalWrite(MOTOR_DRIVE_IN1, LOW);
    digitalWrite(MOTOR_DRIVE_IN2, HIGH);
}

void virajStanga() {
    digitalWrite(MOTOR_STEER_IN1, HIGH);
    digitalWrite(MOTOR_STEER_IN2, LOW);
}

void virajDreapta() {
    digitalWrite(MOTOR_STEER_IN1, LOW);
    digitalWrite(MOTOR_STEER_IN2, HIGH);
}

void testMotoare() {
    mersInainte();
    delay(2000);
    oprireMotoare();
    delay(1000);

    mersInapoi();
    delay(2000);
    oprireMotoare();
    delay(1000);

    virajStanga();
    delay(200);
    oprireMotoare();
    delay(1000);

    virajDreapta();
    delay(200);
    oprireMotoare();
}
