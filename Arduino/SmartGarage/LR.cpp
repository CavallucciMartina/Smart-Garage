#include "LedLazy.h"
#include "Arduino.h"

#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS 0

int brightness;
int fadeAmount;

LedLazy::LedLazy(int pin){
  this->pin = pin;
  pinMode(pin,OUTPUT);
  brightness = 0;
  fadeAmount = 5;
};

void LedLazy::switchOn(){
	  while (brightness < MAX_BRIGHTNESS){
		brightness += fadeAmount;
		analogWrite(pin, brightness);
		delay(20);
	};
}

void LedLazy::switchOff(){
	  while (brightness > MIN_BRIGHTNESS) {
		brightness -= fadeAmount;
		analogWrite(pin, brightness);
		delay(20);
	};
};
