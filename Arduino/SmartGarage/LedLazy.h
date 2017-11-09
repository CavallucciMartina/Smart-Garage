#ifndef __LED_LAZY__
#define __LED_LAZY__

#include "Light.h"

#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS 0
#define LED_DELAY 40

class LedLazy: public Light { 

  public:
  LedLazy(int pin);
  void switchOn();
  void switchOff();   
  
  protected:
  int pin;  
};

#endif
