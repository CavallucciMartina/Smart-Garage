#include "Timer.h"
#include "GateTask.h"
#include "SupportTask.h"

volatile bool openingRequest;
volatile bool autoReady;
volatile bool parked;
Timer timer;
GateTask gateTask(6, 5);
SupportTask supportTask(3, 4, 8, 9, 10);

void setup() {
  Serial.begin(9600);
  gateTask.init();
  supportTask.init();
  timer.setupPeriod(5000);
}

void loop() {
  timer.waitForNextTick();
  gateTask.tick();
  supportTask.tick();
}
