#include "Timer.h"
#include "gateTask.h"

Timer timer;
GateTask gateTask(3,4,5,6);

void setup() {
  gateTask.init();
  timer.setupPeriod(500);
}

void loop() {
  timer.waitForNextTick();
  gateTask.tick();
}
