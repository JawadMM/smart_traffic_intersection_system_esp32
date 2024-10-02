#ifndef LIGHTCONTROL_H
#define LIGHTCONTROL_H

// Declare colors
const int RED_COLOR[];
const int YELLOW_COLOR[];
const int GREEN_COLOR[];
const int OFF[];

// Declare functions
void setRGBColor(int rgbPins[], const int color[]);
void startLightsCycle();

#endif