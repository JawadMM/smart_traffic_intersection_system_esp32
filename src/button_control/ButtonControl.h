#ifndef BUTTONCONTROL_H
#define BUTTONCONTROL_H
#include <Arduino.h>
// Flag to indicate train status
extern volatile bool trainIsApproaching;

// Declare the interrupt service routine (ISR)
void IRAM_ATTR handleButtonPress();

#endif // BUTTONCONTROL_H
