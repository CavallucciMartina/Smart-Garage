#ifndef __GATE_TASK__
#define __GATE_TASK__

#define TIMEOUT 10000

#include "Task.h"
#include "LedLazy.h"
#include "Led.h"
#include "PassiveInfraRed.h"
#include "WString.h"

class GateTask: public Task {
 
  long initialTime;
	int pinLR;
	int pinLDIST1;
	int pinLDIST2;
	int pinPIR;
	Light* LR;
	Light* LDIST1;
	Light* LDIST2;
	Presence* PIR;
	enum {WAITING, OPENING, CLOSING, CAR} state;
	
	public:
	GateTask(int pinLR, int pinLDIST1, int pinLDIST2, int pinPIR);
	void init();
	void tick();
};

#endif
