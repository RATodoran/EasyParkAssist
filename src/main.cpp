
#include <Arduino.h>
#include <Wire.h>

#include "sensors.h"
#include "display.h"
#include "motors.h"
#include "bluetooth.h"

uint16_t distante[4];
bool senzoriOK = false;

unsigned long timpCitire = 0;

void setup() {

    Serial.begin(9600);
    Wire.begin();

    // Initializare motoare
    initializareMotoare();
    oprireMotoare();

    // Initializare Bluetooth
    initializareBluetooth();

    // Initializare LCD
    initDisplay();
    showMessage("EasyParkAssist");
    delay(1000);

    // Initializare senzori
    showMessage("Pornire senzori");
    senzoriOK = initSensors();

    if (senzoriOK) {
        showMessage("Senzori OK");
        Serial.println("Toti senzorii initializati");
    }
    else {
        showMessage("Eroare senzori");
        Serial.println("Eroare initializare senzori");
    }

    delay(1000);
    Serial.println("Sistem pornit!");
}

void loop() {

    // Test comunicatie Bluetooth
    testBluetooth();

    // Citire senzori la fiecare 300 ms
    if (millis() - timpCitire >= 300) {

        timpCitire = millis();

        if (senzoriOK) {

            readSensors(distante);

            Serial.print("S1: ");
            Serial.print(distante[0]);

            Serial.print(" | S2: ");
            Serial.print(distante[1]);

            Serial.print(" | S3: ");
            Serial.print(distante[2]);

            Serial.print(" | S4: ");
            Serial.println(distante[3]);

            showDistances(distante);
        }
    }
}
