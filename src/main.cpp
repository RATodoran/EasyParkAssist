
#include <Arduino.h>
#include "motors.h"
#include "bluetooth.h"

void setup() {
    initializareMotoare();
    oprireMotoare();

    initializareBluetooth();
}

void loop() {
    // pentru testare, se decomaneteaza toate liniile inafara de cea utilizata pentru testarea functiei dorite
    // ATENTIE: toate modulele sunt conectate pana acum la alimentare de la arduino, deci nu se pot testa simultan mai multe module, deoarece acestea vor interfera intre el

    // de aici modulele spre testare
    
    //testBluetooth();
    //testMotoare();
}
