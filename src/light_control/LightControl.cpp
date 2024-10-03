#include "LightControl.h"
#include <Arduino.h>
#include "../setup/ConfigurePins.h"
#include "../button_control/ButtonControl.h"

// initialize variables
int RED_COLOR[] = {255, 0, 14};
int YELLOW_COLOR[] = {255, 119, 0};
int GREEN_COLOR[] = {0, 150, 0};
// int OFF[] = {0, 0, 0};

// Get RGB LED pins
int pinsA[] = RGB_LED_A_PINS;
int pinsB[] = RGB_LED_B_PINS;

// Timing durations in milliseconds
// unsigned long GREEN_DURATION;   // Green light duration: 10 seconds
const unsigned long YELLOW_DURATION = 3000;    // Yellow light duration: 2 seconds

unsigned long previousMillis = 0; // Store last time state changed

// Variables to manage state
enum TrafficLightState {GREEN, YELLOW, RED};
TrafficLightState lightAState = GREEN;
TrafficLightState lightBState = RED;

void setRGBColor(int rgbPins[], int color[]) {
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

void startLightsCycle(int greenDurationA) {
    // Update the traffic light colors
    setTrafficLightsColor();

    // int greenDurationA = durations[0];
    int greenDurationB = (30 - greenDurationA) * 1000;

    unsigned long currentMillis = millis();

    // Manage the state transition
    if (lightAState == GREEN && currentMillis - previousMillis >= greenDurationA * 1000) {
        // Switch to yellow after green duration
        lightAState = YELLOW;
        previousMillis = currentMillis;
        Serial.print("Turning A YELLOW for ");
        Serial.print(YELLOW_DURATION / 1000);
        Serial.println("s");


    } else if (lightAState == YELLOW && currentMillis - previousMillis >= YELLOW_DURATION) {
        // Switch A to red after yellow duration
        lightAState = RED;
        // Switch B to green
        lightBState = GREEN;
        previousMillis = currentMillis;
        Serial.print("Turning B GREEN for ");
        Serial.print(greenDurationB / 1000);
        Serial.println("s");
        Serial.print("Turning A RED for ");
        Serial.print((greenDurationB + YELLOW_DURATION) / 1000);
        Serial.println("s");



    } else if (lightBState == GREEN && currentMillis - previousMillis >= greenDurationB) {
        // Switch B to yellow after green duration
        lightBState = YELLOW;
        previousMillis = currentMillis;
        Serial.print("Turning B YELLOW for ");
        Serial.print(YELLOW_DURATION / 1000);
        Serial.println("s");


    } else if (lightBState == YELLOW && currentMillis - previousMillis >= YELLOW_DURATION) {
        // Switch B to red after yellow duration
        lightBState = RED;
        lightAState = GREEN;
        previousMillis = currentMillis;
        Serial.print("Turning A GREEN for ");
        Serial.print(greenDurationA);
        Serial.println("s");
        Serial.print("Turning B RED for ");
        Serial.print((greenDurationA * 1000 + YELLOW_DURATION) / 1000);
        Serial.println("s");
    } else if (lightAState == RED && lightBState == RED) {
        lightAState = GREEN;
        previousMillis = currentMillis;
        Serial.print("Turning A GREEN for ");
        Serial.print(greenDurationA);
        Serial.println("s");
        Serial.print("Turning B RED for ");
        Serial.print((greenDurationA * 1000 + YELLOW_DURATION) / 1000);
        Serial.println("s");
    }

    delay(10);
    
}

void turnAllLightsRed() {
    Serial.println("TURNING LIGHTS RED...");
    setRGBColor(pinsA, RED_COLOR);
    setRGBColor(pinsB, RED_COLOR);
    lightAState = RED;
    lightBState = RED;
    delay(5000);
}


