#include <Arduino.h>
#include "./setup/ConfigurePins.h"
#include "./light_control/LightControl.h"

void setup() {
  Serial.begin(9600);

  configurePins();

  Serial.println("Setup complete. Reading potentiometer...");
}

void loop() {

  startLightsCycle();

  // Read potentiometer value
  // int potValue = analogRead(POTENTIOMETER_PIN);
  // Serial.print("Potentiometer Value: ");
  // Serial.println(potValue);
  // delay(500);
}
