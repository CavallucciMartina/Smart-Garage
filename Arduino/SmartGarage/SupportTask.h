/*
  This task helps the user to parking the car giving him some information.
*/

#ifndef __SUPPORT_TASK__
#define __SUPPORT_TASK__

#include "Task.h"
#include "Led.h"
#include "Sonar.h"
#include "ButtonImpl.h"
#include "WString.h"

class SupportTask: public Task {

  int pinLDIST1;
  int pinLDIST2;
  int pinEcho;
  int pinTrig;
  int pinTouch;
  Light* LDIST1;
  Light* LDIST2;
  ProximitySensor* PROX;
  Button* TOUCH;
  enum {WAITING, ENTERING, MIDDLE, END, TOUCHING} state;
  
  public:
  SupportTask(int pinLDIST1, int pinLDIST2, int pinEcho, int pinTrig, int pinTouch);
  void init();
  void tick();
};

#endif
