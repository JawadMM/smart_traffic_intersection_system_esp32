#include "ConfigurePins.h"

// Pin assignment for potentiometer
#define POT_PIN 1

// Pin assignment for push button
#define BUTTON_PIN 21



void configurePins() {
  // INPUT PINS SETUP
  // Setup for potentiometer
  pinMode(POT_PIN, INPUT);

  // Setup for button
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  
}