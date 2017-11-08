#include "Timer.h"
#include "GateTask.h"
#include "SupportTask.h"
#include "CloseTask.h"
#include "ForcedCloseTask.h"

volatile bool openingRequest;
volatile bool autoReady;
volatile bool parked;
Timer timer;
GateTask gateTask(6, 5);
SupportTask supportTask(3, 4, 8, 9, 7);
CloseTask closeTask(8, 9);
ForcedCloseTask forcedCloseTask(8, 9, 10);

void setup() {
  Serial.begin(9600);
  gateTask.init();
  supportTask.init();
  closeTask.init();
  forcedCloseTask.init();
  timer.setupPeriod(150);
}

void loop() {
  timer.waitForNextTick();
  gateTask.tick();
  supportTask.tick();
  closeTask.tick();
  forcedCloseTask.tick();
}
