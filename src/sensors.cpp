
#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include "sensors.h"

#define XSHUT_1 A0
#define XSHUT_2 A1
#define XSHUT_3 A2
#define XSHUT_4 A3

VL53L0X senzor1;
VL53L0X senzor2;
VL53L0X senzor3;
VL53L0X senzor4;

bool initSensors() {

    const uint8_t pini[4] = {
        XSHUT_1, XSHUT_2, XSHUT_3, XSHUT_4
    };

    VL53L0X* senzori[4] = {
        &senzor1, &senzor2, &senzor3, &senzor4
    };

    // Oprim toti senzorii
    for (int i = 0; i < 4; i++) {
        digitalWrite(pini[i], LOW);
        pinMode(pini[i], OUTPUT);
    }

    delay(20);

    // Pornim si initializam senzorii pe rand
    for (int i = 0; i < 4; i++) {

        // Eliberam XSHUT fara a aplica 5V pe pin
        pinMode(pini[i], INPUT);
        delay(20);

        senzori[i]->setTimeout(500);

        if (!senzori[i]->init()) {
            Serial.print(F("Eroare senzor "));
            Serial.println(i + 1);
            return false;
        }

        senzori[i]->setAddress(0x30 + i);
        senzori[i]->startContinuous();

        Serial.print(F("Senzor "));
        Serial.print(i + 1);
        Serial.println(F(" initializat"));
    }

    return true;
}

void readSensors(uint16_t distante[4]) {

    distante[0] = senzor1.readRangeContinuousMillimeters();
    if (senzor1.timeoutOccurred()) distante[0] = 65535;

    distante[1] = senzor2.readRangeContinuousMillimeters();
    if (senzor2.timeoutOccurred()) distante[1] = 65535;

    distante[2] = senzor3.readRangeContinuousMillimeters();
    if (senzor3.timeoutOccurred()) distante[2] = 65535;

    distante[3] = senzor4.readRangeContinuousMillimeters();
    if (senzor4.timeoutOccurred()) distante[3] = 65535;
}
