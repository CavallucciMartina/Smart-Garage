/*
  This task checks if the user wants to close the garage and if that action is allowed.
*/

#ifndef __CLOSE_TASK__
#define __CLOSE_TASK__

#include "Task.h"
#include "Sonar.h"
#include "WString.h"

class CloseTask: public Task {
 
  int pinEcho;
  int pinTrig;
  Sonar* PROX;
  enum {WAITING, CTRL} state;
  
  public:
  CloseTask(int pinEcho, int pinTrig);
  void init();
  void tick();
};

#endif
