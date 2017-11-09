#include "CloseTask.h"
#include "Arduino.h"
#include "GlobalVar.h"

CloseTask::CloseTask(int pinEcho, int pinTrig) {
  this->pinEcho = pinEcho;
  this->pinTrig = pinTrig;
}

void CloseTask::init() {
  PROX = new Sonar(pinEcho, pinTrig);
  state = WAITING;
}

void CloseTask::tick() {
  switch (state) {
    
    case WAITING:
       if (openingRequest && autoReady && !parked && Serial.available() && String("CLOSE").equals(Serial.readString())) {
          state = CTRL;
       }
       break;
       
    case CTRL:
       if (PROX->getDistance()<DISTMIN){
           parked = true;
           Serial.println("OK");
           delay(PRINT_DELAY);
           state = WAITING;
       }
       if (PROX->getDistance()>DISTCLOSE){
           Serial.println("TOO FAR");
           delay(PRINT_DELAY);
       }
       break;
    }
}
