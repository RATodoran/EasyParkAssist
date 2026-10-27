
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "display.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void initDisplay() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void showMessage(const char* mesaj) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(mesaj);
}

void showDistances(const uint16_t distante[4]) {

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(F("1:"));
    if (distante[0] == 65535) lcd.print(F("ERR"));
    else lcd.print(distante[0]);

    lcd.setCursor(8, 0);
    lcd.print(F("2:"));
    if (distante[1] == 65535) lcd.print(F("ERR"));
    else lcd.print(distante[1]);

    lcd.setCursor(0, 1);
    lcd.print(F("3:"));
    if (distante[2] == 65535) lcd.print(F("ERR"));
    else lcd.print(distante[2]);

    lcd.setCursor(8, 1);
    lcd.print(F("4:"));
    if (distante[3] == 65535) lcd.print(F("ERR"));
    else lcd.print(distante[3]);
}
