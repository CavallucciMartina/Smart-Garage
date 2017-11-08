#include "Timer.h"
#include "GateTask.h"
#include "SupportTask.h"
#include "CloseTask.h"

volatile bool openingRequest;
volatile bool autoReady;
volatile bool parked;
Timer timer;
GateTask gateTask(6, 5);
SupportTask supportTask(3, 4, 8, 9, 7);
CloseTask closeTask(8, 9);

void setup() {
  Serial.begin(9600);
  gateTask.init();
  supportTask.init();
  closeTask.init();
  timer.setupPeriod(200);
}

void loop() {
  timer.waitForNextTick();
  gateTask.tick();
  supportTask.tick();
  closeTask.tick();
  supportTask.tick();
}
