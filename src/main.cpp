#include <Arduino.h>

void setup() {
    DDRB |= (1 << DDB0);
}

void loop() {
    PORTB ^= (1 << PORTB0);
    delay(1000);
}