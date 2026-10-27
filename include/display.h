
#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

void initDisplay();
void showMessage(const char* mesaj);
void showDistances(const uint16_t distante[4]);

#endif
