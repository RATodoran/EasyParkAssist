
#include <Arduino.h>
#include <SoftwareSerial.h>

#include "bluetooth.h"
#include "config.h"

SoftwareSerial bluetooth(BT_RX_PIN, BT_TX_PIN);

void initializareBluetooth() {
    bluetooth.begin(SERIAL_BAUD);
    Serial.println(F("Bluetooth pregatit!"));
}

void testBluetooth() {
    if (bluetooth.available() > 0) {
        char mesaj = bluetooth.read();

        Serial.print(F("Primit: "));
        Serial.println(mesaj);
    }
}
