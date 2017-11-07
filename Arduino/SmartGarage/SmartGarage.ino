#include "Timer.h"
#include "gateTask.h"

Timer timer;
GateTask gateTask(10,12,11,2);

void setup() {
  Serial.begin(9600);
  gateTask.init();
  timer.setupPeriod(500);
}

void loop() {
  timer.waitForNextTick();
  gateTask.tick();
}
