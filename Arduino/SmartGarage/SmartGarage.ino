#include "Timer.h"
#include "GateTask.h"
#include "SupportTask.h"
#include "CloseTask.h"
#include "ForcedCloseTask.h"

/*PIN numbers definiton*/
#define PIN_LDIST1 3
#define PIN_LDIST2 4
#define PIN_PIR 5
#define PIN_LR 6
#define PIN_TOUCH 7
#define PIN_ECHO 8
#define PIN_TRIG 9
#define PIN_CLOSE 10
/*Scheduler time period definition*/
#define TIME_PERIOD 200
/*Bit rate definition for serial communication*/
#define BIT_RATE 9600

/*Global variables initialization*/
volatile bool openingRequest;
volatile bool autoReady;
volatile bool parked;

/*Tasks instances*/
Timer timer;
GateTask gateTask(PIN_LR, PIN_PIR);
SupportTask supportTask(PIN_LDIST1, PIN_LDIST2, PIN_ECHO, PIN_TRIG, PIN_TOUCH);
CloseTask closeTask(PIN_ECHO, PIN_TRIG);
ForcedCloseTask forcedCloseTask(PIN_ECHO, PIN_TRIG, PIN_CLOSE);

void setup() {
  Serial.begin(BIT_RATE);
  gateTask.init();
  supportTask.init();
  closeTask.init();
  forcedCloseTask.init();
  timer.setupPeriod(TIME_PERIOD);
}

void loop() {
  timer.waitForNextTick();
  gateTask.tick();
  supportTask.tick();
  closeTask.tick();
  forcedCloseTask.tick();
}
