#include "LightControl.h"
#include <Arduino.h>
#include "../setup/ConfigurePins.h"
#include "../button_control/ButtonControl.h"

// initialize variables
const int RED_COLOR[] = {255, 0, 14};
const int YELLOW_COLOR[] = {255, 119, 0};
const int GREEN_COLOR[] = {0, 150, 0};
// int OFF[] = {0, 0, 0};

// Get RGB LED pins
int pinsA[] = RGB_LED_A_PINS;
int pinsB[] = RGB_LED_B_PINS;

// Timing durations in milliseconds
const unsigned long GREEN_DURATION = 5000;   // Green light duration: 10 seconds
const unsigned long YELLOW_DURATION = 2000;    // Yellow light duration: 2 seconds

unsigned long previousMillis = 0; // Store last time state changed

// Variables to manage state
enum TrafficLightState {GREEN, YELLOW, RED};
TrafficLightState lightAState = GREEN;
TrafficLightState lightBState = RED;


void setRGBColor(int rgbPins[], const int color[]) {
    for (int i = 0; i < 3; i++) {
        analogWrite(rgbPins[i], 255 - color[i]);
    }
}

void setTrafficLightsColor() {
    if (lightAState == GREEN) {
        setRGBColor(pinsA, GREEN_COLOR); // Light A Green
        setRGBColor(pinsB, RED_COLOR); // Light B Red
        // Serial.println("A green");

    } else if (lightAState == YELLOW) {
        setRGBColor(pinsA, YELLOW_COLOR); // Light A Yellow
        setRGBColor(pinsB, RED_COLOR); // Light B Red
        // Serial.println("A yellow");

    } else if (lightAState == RED && lightBState == GREEN) {
        setRGBColor(pinsA, RED_COLOR); // Light A Red
        setRGBColor(pinsB, GREEN_COLOR); // Light B Green
        // Serial.println("A red");

    } else if (lightBState == YELLOW) {
        setRGBColor(pinsA, RED_COLOR); // Light A Red
        setRGBColor(pinsB, YELLOW_COLOR); // Light B Yellow
        // Serial.println("B yellow");

    } else if (lightBState == RED) {
        setRGBColor(pinsA, GREEN_COLOR); // Light A Green
        setRGBColor(pinsB, RED_COLOR); // Light B Red
        // Serial.println("B red");

    }
}

void startLightsCycle() {
    // Update the traffic light colors
    setTrafficLightsColor();
    unsigned long currentMillis = millis();

    // Manage the state transition
    if (lightAState == GREEN && currentMillis - previousMillis >= GREEN_DURATION) {
        // Switch to yellow after green duration
        lightAState = YELLOW;
        previousMillis = currentMillis;

    } else if (lightAState == YELLOW && currentMillis - previousMillis >= YELLOW_DURATION) {
        // Switch A to red after yellow duration
        lightAState = RED;
        // Switch B to green
        lightBState = GREEN;
        previousMillis = currentMillis;

    } else if (lightBState == GREEN && currentMillis - previousMillis >= GREEN_DURATION) {
        // Switch B to yellow after green duration
        lightBState = YELLOW;
        previousMillis = currentMillis;

    } else if (lightBState == YELLOW && currentMillis - previousMillis >= YELLOW_DURATION) {
        // Switch B to red after yellow duration
        lightBState = RED;
        lightAState = GREEN;
        previousMillis = currentMillis;
    }
    delay(10);

}

