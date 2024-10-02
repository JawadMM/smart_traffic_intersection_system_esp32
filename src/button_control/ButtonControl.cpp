#include "ButtonControl.h"
#include <Arduino.h>
// Define the variable
volatile bool trainIsApproaching = false;

// Implementation of handleButtonPress
void IRAM_ATTR handleButtonPress() {
    trainIsApproaching = true;
}
