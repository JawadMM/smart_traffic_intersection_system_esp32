#include "ConfigurePins.h"

void configurePins() {
  // INPUT PINS SETUP
  // Setup for potentiometer
  pinMode(POTENTIOMETER_PIN, INPUT);

  // Setup for button
  pinMode(PUSH_BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PUSH_BUTTON_PIN), handleButtonPress, FALLING);

  //OUTPUT PINS SETUP
  // Setup for RGB LED Lights
  int pins[] = RGB_LED_A_PINS;
  for (int i = 0; i < 3; i++) {
    pinMode(pins[i], OUTPUT);
  }

  int pins[] = RGB_LED_B_PINS;
  for (int i = 0; i < 3; i++) {
    pinMode(pins[i], OUTPUT);
  }
  
  // Setup for buzzer
  pinMode(BUZZER_PIN, OUTPUT);
  
}

void IRAM_ATTR handleButtonPress() {

}