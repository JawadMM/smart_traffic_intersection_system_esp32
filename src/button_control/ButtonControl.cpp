#include "ButtonControl.h"
#include <Arduino.h>

// initialize a flag variable to check if there is a train approaching
volatile bool trainIsApproaching = false;

// Implementation of handleButtonPress
void IRAM_ATTR handleButtonPress() {
    // Make the train flag true when the button is pressed
    trainIsApproaching = true;
}
