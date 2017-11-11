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
       if (openingRequest && autoReady && !parked) {
          Serial.println("Welcome Home.");
          delay(PRINT_DELAY);
          state = ENTERING;
       }
       break;
       
    case ENTERING:
       if (!openingRequest || !autoReady || parked) {
          state = WAITING;
       }
       else {
          Serial.println("DISTANCE: " + (String)PROX->getDistance());
          delay(PRINT_DELAY);
       }
       if (PROX->getDistance()<=DISTMAX) {
        LDIST1->switchOn();
        state = MIDDLE;
       }
       break;
       
    case MIDDLE:
       if (!openingRequest || !autoReady || parked) {
          LDIST1->switchOff();
          state = WAITING;
       }
       else {
          Serial.println("DISTANCE: " + (String)PROX->getDistance());
          delay(PRINT_DELAY);
       }
       if (PROX->getDistance()<=DISTMIN) {
        LDIST2->switchOn();
        state = END;
       }
       if (PROX->getDistance()>DISTMAX) {
        LDIST1->switchOff();
        state = ENTERING;
       }
       break;
       
    case END:
       if (!openingRequest || !autoReady || parked) {
          LDIST1->switchOff();
          LDIST2->switchOff();
          state = WAITING;
       }
       else {
          Serial.println("OK CAN STOP");
          delay(PRINT_DELAY);
       }
       
       if (TOUCH->isPressed()) {
          wall = true;
          state = TOUCHING;
       }
       if (PROX->getDistance()>DISTMIN) {
        LDIST2->switchOff();
        state = MIDDLE;
       }
       break;

     case TOUCHING:
        if (!openingRequest || !autoReady || parked) {
          LDIST1->switchOff();
          LDIST2->switchOff();
          state = WAITING;
       }
       else {
          Serial.println("TOUCHING");
          delay(PRINT_DELAY);
        }
       if (!(TOUCH->isPressed())) {
          wall = false;
          state = END;
       }
       break;
    }
}
