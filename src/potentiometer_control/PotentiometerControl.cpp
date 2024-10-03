#include "../setup/ConfigurePins.h"
#include <Arduino.h>

int potentiometerValue;


void readPotentiometerValue() {
  // Read potentiometer value
  int readValue = analogRead(POTENTIOMETER_PIN);
  // Serial.print("Potentiometer Value: ");
  // Serial.println(readValue);
  int convertedValue = map(readValue, 0, 4095, 10, 20);
  // Serial.print("Converted Potentiometer Value: ");
  // Serial.println(convertedValue);
  potentiometerValue = convertedValue;
}

