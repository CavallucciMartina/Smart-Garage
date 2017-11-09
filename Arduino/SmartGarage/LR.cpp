#include "LedLazy.h"
#include "Arduino.h"

int brightness;
int fadeAmount;

LedLazy::LedLazy(int pin){
  this->pin = pin;
  pinMode(pin,OUTPUT);
  analogWrite(pin, MIN_BRIGHTNESS);
  brightness = 0;
  fadeAmount = 5;
};

void LedLazy::switchOn(){
	  while (brightness < MAX_BRIGHTNESS){
		    brightness = brightness+fadeAmount;
		    analogWrite(pin, brightness);
		    delay(LED_DELAY);
	};
}

void LedLazy::switchOff(){
	  while (brightness > MIN_BRIGHTNESS) {
		    brightness = brightness-fadeAmount;
		    analogWrite(pin, brightness);
		    delay(LED_DELAY);
	};
};
