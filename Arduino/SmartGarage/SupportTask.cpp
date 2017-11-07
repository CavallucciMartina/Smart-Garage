#include "SupportTask.h"
#include "Arduino.h"
#include "GlobalVar.h"

SupportTask::SupportTask(int pinLDIST1, int pinLDIST2, int pinEcho, int pinTrig, int pinTouch) {
  this->pinLDIST1 = pinLDIST1;
  this->pinLDIST2 = pinLDIST2;
  this->pinEcho = pinEcho;
  this->pinTrig = pinTrig;
  this->pinTouch = pinTouch;
}

void SupportTask::init() {
  LDIST1 = new Led(pinLDIST1);
  LDIST1->switchOff();
  LDIST2 = new Led(pinLDIST2);
  LDIST2->switchOff();
  PROX = new Sonar(pinEcho, pinTrig);
  TOUCH = new ButtonImpl(pinTouch);
  state = WAITING;
}

void SupportTask::tick() {
  switch (state) {
    
    case WAITING:
       Serial.println("WAITING");
       if (openingRequest && autoReady && !parked) {
          Serial.println("Welcome Home.");
          state = ENTERING;
       }
       break;
       
    case ENTERING:
       Serial.print("ENTERING: ");
       Serial.println(PROX->getDistance());
       if (PROX->getDistance()<=DISTMAX) {
        LDIST1->switchOn();
        state = MIDDLE;
       }
       break;
       
    case MIDDLE:
       Serial.print("MIDDLE: ");
       Serial.println(PROX->getDistance());
       if (PROX->getDistance()<=DISTMIN) {
        LDIST2->switchOn();
        state = END;
       }
       if (PROX->getDistance()>DISTMAX) {
        LDIST1->switchOff();
        state = ENTERING;
       }
       if (parked) {
        LDIST1->switchOff();
        state = WAITING;
       }
       break;
       
    case END:
       Serial.println("OK CAN STOP");
       if (TOUCH->isPressed()) {
          state = TOUCHING;
       }
       if (PROX->getDistance()>DISTMIN) {
        LDIST2->switchOff();
        state = MIDDLE;
       }
       if (parked) {
        LDIST1->switchOff();
        LDIST2->switchOff();
        state = WAITING;
       }
       break;

     case TOUCHING:
       Serial.println("TOUCHING");
       if (!(TOUCH->isPressed())) {
          state = END;
       }
       if (parked) {
        LDIST1->switchOff();
        LDIST2->switchOff();
        state = WAITING;
       }
       break;
    }
}
