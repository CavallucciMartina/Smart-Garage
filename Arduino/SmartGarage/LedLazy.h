#ifndef __LED__
#define __LED__

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
