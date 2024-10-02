#include <Arduino.h>
#include "./setup/ConfigurePins.h"

// Flag to indicate button state
volatile bool buttonIsPressed = false;

// ISR for button press
void IRAM_ATTR handleButtonPress() {
  buttonIsPressed = true;
}

// Function to change LED color based on button state
void changeLEDColor() {
  if (buttonIsPressed) {
    Serial.println("Button Pushed");
    ledcWrite(0, 255); // Set Red to maximum
    ledcWrite(1, 255); // Set Green to maximum
    ledcWrite(2, 0);   // Set Blue to minimum
  } else {
    ledcWrite(0, 0);   // Turn Red off
    ledcWrite(1, 0);   // Turn Green off
    ledcWrite(2, 0);   // Turn Blue off
  }
}

void setup() {
  Serial.begin(9600);

  configurePins();

  Serial.println("Setup complete. Reading potentiometer...");
}

void loop() {
  // Change LED color based on button state
  changeLEDColor();

  // Check button state to reset the flag
  if (digitalRead(PUSH_BUTTON_PIN) == HIGH) {
    buttonIsPressed = false; // Reset flag when button is not pressed
  }

  // Read potentiometer value
  int potValue = analogRead(POTENTIOMETER_PIN);
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);
  delay(500);
}
