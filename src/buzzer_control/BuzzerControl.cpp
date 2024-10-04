#include "BuzzerControl.h"
#include "../setup/ConfigurePins.h"
#include "../button_control/ButtonControl.h"
#include "../light_control/LightControl.h"
#include <Arduino.h>

void activateTrainSound(int seconds) {

    // Activate the buzzer
    tone(BUZZER_PIN, 500);  // Set buzzer frequency to 500 Hz

    // Blink the built-in LED
    blinkBuiltInLED(seconds);

    // Deactivate the buzzer
    noTone(BUZZER_PIN);

}
