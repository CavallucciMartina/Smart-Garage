#ifndef __FORCED_CLOSE_TASK__
#define __FORCED_CLOSE_TASK__

#include "Task.h"
#include "Sonar.h"
#include "ButtonImpl.h"
#include "WString.h"

class ForcedCloseTask: public Task {
 
  int pinEcho;
  int pinTrig;
  int pinCLOSE;
  Sonar* PROX;
  ButtonImpl* CLOSE;
  enum {WAITING} state;
  
  public:
  ForcedCloseTask(int pinEcho, int pinTrig, int pinCLOSE);
  void init();
  void tick();
};

#endif