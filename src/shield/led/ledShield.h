#ifndef H_LESSHIELD
#define H_LESSHIELD

#include <Arduino.h>

void setupLedShield();
void ledRight(byte intensity1);
void ledLeft(byte intensity2);
void ledBefore(byte intensity3);
void ledBack(byte intensity4);
void buzzerTone(int hz,int timer);


#endif