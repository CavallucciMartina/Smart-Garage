#ifndef __SONAR__
#define __SONAR__

#include "ProximitySensor.h"

class Sonar: public ProximitySensor {

public:  
  Sonar(int pinEcho, int pinTrig);
  float getDistance();
  
private:
    const float vs = 331.5 + 0.6*20;
    int pinEcho, pinTrig;
};

#endif 
