#include <Arduino.h>
#include "./setup/ConfigurePins.h"
#include "./light_control/LightControl.h"
#include "./potentiometer_control/PotentiometerControl.h"
#include "./button_control/ButtonControl.h"

void setup() {
  Serial.begin(9600);

  configurePins();

  Serial.println("Setup complete. Reading potentiometer...");
}

void loop() {

  if (trainIsApproaching) {
    turnAllLightsRed();
    trainIsApproaching = false;
    Serial.println("BACK TO CYCLE...");
  }

  readPotentiometerValue();
  // Serial.print("in main:");
  // Serial.println(potentiometerValue);

  startLightsCycle(potentiometerValue);
}
