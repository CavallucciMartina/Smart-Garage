#ifndef __LED_LAZY__
#define __LED_LAZY__

#include "Light.h"

class LedLazy: public Light { 

  public:
  LedLazy(int pin);
  void switchOn();
  void switchOff();   
  
  protected:
  int pin;  
};

#endif
