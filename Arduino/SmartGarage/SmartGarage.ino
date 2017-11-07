#include "Timer.h"
#include "gateTask.h"

Timer timer;
GateTask gateTask(6,3,4,5);

void setup() {
  Serial.begin(9600);
  gateTask.init();
  timer.setupPeriod(5000);
}

void loop() {
  timer.waitForNextTick();
  gateTask.tick();
}
