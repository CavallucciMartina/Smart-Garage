#ifndef __GATE_TASK__
#define __GATE_TASK__

#define TIMEOUT 10000

#include "Task.h"
#include "LedLazy.h"
#include "PassiveInfraRed.h"
#include "WString.h"

class GateTask: public Task {
 
  long initialTime;
	int pinLR;
	int pinPIR;
	Light* LR;
	Presence* PIR;
	enum {WAITING, OPENING, CLOSING, CAR} state;
	
	public:
	GateTask(int pinLR, int pinPIR);
	void init();
	void tick();
};

#endif
