#ifndef LIGHTCONTROL_H
#define LIGHTCONTROL_H

// Define colors
const int RED[] = {239, 57, 50};
const int YELLOW[] = {238, 188, 25};
const int GREEN[] = {66, 198, 0};
const int OFF[] = {0, 0, 0};

// Declare functions
void setLightColor(int rgbPins[], int color[]);

#endif