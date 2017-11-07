#include "Timer.h"
#include "gateTask.h"
#include "GlobalVar.h"

Timer timer;
GateTask gateTask(5,3,4,6);

void setup() {
  gateTask.init();
  timer.setupPeriod(500);
  openinigRequest = false;
  autoReady = false;
  parked = false;
}

void loop() {
  timer.waitForNextTick();
  gateTask.tick();
}
