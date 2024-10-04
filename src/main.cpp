#include <Arduino.h>
#include "./setup/ConfigurePins.h"
#include "./light_control/LightControl.h"
#include "./potentiometer_control/PotentiometerControl.h"
#include "./button_control/ButtonControl.h"
#include "./buzzer_control/BuzzerControl.h"

const int trainAppraochInterval = 15;
int potentiometerValue;

void setup() {
  Serial.begin(9600);

  configurePins();

  Serial.println("Setup complete.");
}

void loop() {

  // Check if there is a train coming
  if (trainIsApproaching) {
    turnAllLightsRed();
    activateTrainSound(trainAppraochInterval);
    trainIsApproaching = false;
    Serial.println("BACK TO CYCLE...");
  }

  //Read the value of the potentiometer to determine the durations for traffic lights
  potentiometerValue = readPotentiometerValue();

  // Start the traffic lights cycle
  startLightsCycle(potentiometerValue);
}
