
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "bluetooth.h"

const int BT_RX = 10;
const int BT_TX = 11;

SoftwareSerial bluetooth(BT_RX, BT_TX);

void initializareBluetooth() {
    Serial.begin(9600);
    bluetooth.begin(9600);

    Serial.println("Bluetooth pregatit!");
}

void testBluetooth() {
    if (bluetooth.available()) {
        char mesaj = bluetooth.read();

        Serial.print("Primit: ");
        Serial.println(mesaj);
    }
}
