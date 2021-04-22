#include <main.h>

void setup() {
  #ifdef DEBUGSERIAL
		Serial.begin(115200);
	#endif
	LOG("setup")

  pinMode(PixelPin, OUTPUT);

	Strip.Begin();

	delay(1000);

	if (! myRtc.begin()) {
    LOG("RTC erroro")
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}