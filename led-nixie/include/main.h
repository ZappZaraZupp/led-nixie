#ifndef H_MAIN
#define H_MAIN

#define DEBUGSERIAL
#ifdef DEBUGSERIAL
#define LOG(arg) Serial.print("[");Serial.print((const char*)__FUNCTION__);Serial.print("] ");Serial.print(arg);Serial.print("\r\n");
#else
#define LOG(arg) ;
#endif

////////////////////////////////////
// includes
#include <Arduino.h>
#include <RTClib.h>
#include <NeoPixelBus.h>
#include <NeoPixelAnimator.h>

////////////////////////////////////
// Global Variables
RTC_DS3231 myRtc;
DateTime timeNow;
DateTime prevTimeNow;

/////////////////////////////////////
// LEDs
const uint8_t PixelCount = 100;
const uint8_t PixelPin = 18;
NeoPixelBus <NeoGrbFeature, Neo800KbpsMethod> Strip(PixelCount, PixelPin);
NeoPixelAnimator PanelAnimation(PanelPixelCount + MinutesPixelCount, NEO_CENTISECONDS);

struct PanelAnimationState
{
    RgbColor StartingColor;  // the color the animation starts at
    RgbColor EndingColor; // the color the animation will end at
}; 

PanelAnimationState StripState[PixelCount];

#endif