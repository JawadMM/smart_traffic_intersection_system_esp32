#include <Arduino.h>

// Pin assignments for RGB LED A
#define LEDA_R 42
#define LEDA_G 41
#define LEDA_B 40

// Pin assignment for RGB LED B
#define LEDB_R 39  // Red pin
#define LEDB_G 38  // Green pin
#define LEDB_B 37  // Blue pin

// Pin assignment for potentiometer
#define POT_PIN 1

// Pin assignment for push button
#define BUTTON_PIN 21

// Pin assignment for buzzer
#define BUZZER_PIN 19

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

  // OUTPUT PINS SETUP
  // Set up PWM for RGB LED A
  ledcSetup(0, 5000, 8); // Channel 0 for LED A Red
  ledcAttachPin(LEDA_R, 0); // Attach Red pin to channel 0

  ledcSetup(1, 5000, 8); // Channel 1 for LED A Green
  ledcAttachPin(LEDA_G, 1); // Attach Green pin to channel 1

  ledcSetup(2, 5000, 8); // Channel 2 for LED A Blue
  ledcAttachPin(LEDA_B, 2); // Attach Blue pin to channel 2

  // Set up PWM for RGB LED B
  ledcSetup(3, 5000, 8); // Channel 3 for LED B Red
  ledcAttachPin(LEDB_R, 3); // Attach Red pin to channel 3

  ledcSetup(4, 5000, 8); // Channel 4 for LED B Green
  ledcAttachPin(LEDB_G, 4); // Attach Green pin to channel 4

  ledcSetup(5, 5000, 8); // Channel 5 for LED B Blue
  ledcAttachPin(LEDB_B, 5); // Attach Blue pin to channel 5
  
  // Setup for buzzer
  pinMode(BUZZER_PIN, OUTPUT);

  // INPUT PINS SETUP
  // Setup for potentiometer
  pinMode(POT_PIN, INPUT);

  // Setup for button
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButtonPress, FALLING);

  Serial.println("Setup complete. Reading potentiometer...");
}

void loop() {
  // Change LED color based on button state
  changeLEDColor();

  // Check button state to reset the flag
  if (digitalRead(BUTTON_PIN) == HIGH) {
    buttonIsPressed = false; // Reset flag when button is not pressed
  }

  // Read potentiometer value
  int potValue = analogRead(POT_PIN);
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);
  delay(500);
}
