#include "LightControl.h"
#include <Arduino.h>
#include "../setup/ConfigurePins.h"

void setLightColor(int rgbPins[], int color[]) {
    for (int i = 0; i < 3; i++) {
        analogWrite(rgbPins[i], color[i]);
    }
}



