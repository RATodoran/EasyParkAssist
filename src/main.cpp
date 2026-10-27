
#include <Arduino.h>
#include <Wire.h>

#include "config.h"
#include "sensors.h"
#include "display.h"
#include "motors.h"
#include "bluetooth.h"

uint16_t distante[4];
bool senzoriOK = false;
unsigned long timpCitire = 0;

void setup() {

    Serial.begin(SERIAL_BAUD);

    initializareMotoare();
    oprireMotoare();

    initializareBluetooth();

    Wire.begin();

    initDisplay();
    showMessage("EasyParkAssist");
    delay(1000);

    showMessage("Pornire senzori");
    senzoriOK = initSensors();

    if (senzoriOK) {
        showMessage("Senzori OK");
        Serial.println(F("Senzori initializati"));
    }
    else {
        showMessage("Eroare senzori");
        Serial.println(F("Eroare initializare"));
    }

    delay(1000);
}

void loop() {

    testBluetooth();

    if (millis() - timpCitire >= SENSOR_INTERVAL) {

        timpCitire = millis();

        if (senzoriOK) {

            readSensors(distante);

            Serial.print(F("S1: "));
            Serial.print(distante[0]);

            Serial.print(F(" S2: "));
            Serial.print(distante[1]);

            Serial.print(F(" S3: "));
            Serial.print(distante[2]);

            Serial.print(F(" S4: "));
            Serial.println(distante[3]);

            showDistances(distante);
        }
    }
}
