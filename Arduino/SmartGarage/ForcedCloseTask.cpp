#include "ForcedCloseTask.h"
#include "Arduino.h"
#include "GlobalVar.h"

ForcedCloseTask::ForcedCloseTask(int pinEcho, int pinTrig, int pinCLOSE) {
  this->pinEcho = pinEcho;
  this->pinTrig = pinTrig;
  this->pinCLOSE = pinCLOSE;
}

void ForcedCloseTask::init() {
  PROX = new Sonar(pinEcho, pinTrig);
  CLOSE = new ButtonImpl(pinCLOSE);
  state = WAITING;
}

void ForcedCloseTask::tick() {
  switch (state) {
    
    case WAITING:
       if ((openingRequest && !autoReady && CLOSE->isPressed()) ||
          (openingRequest && autoReady && !parked && CLOSE->isPressed() && PROX->getDistance()<=DISTCLOSE)) {
              parked = true;
              openingRequest = false;
              autoReady = false; 
          }
       break;
  }
}
