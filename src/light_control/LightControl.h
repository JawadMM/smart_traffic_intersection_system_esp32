#ifndef LIGHT_CONTROL_H
#define LIGHT_CONTROL_H

// Declare colors
// int RED_COLOR[3];
// int YELLOW_COLOR[3];
// int GREEN_COLOR[3];
// int OFF[];

// Declare functions
void setRGBColor(int rgbPins[], const int color[]);
void turnAllLightsRed();
void startLightsCycle(int greenDurationA);

#endif