#include "gateTask.h"
#include "Arduino.h"
#include "GlobalVar"

GateTask::GateTask(int pinLR, int pinLDIST1, int pinLDIST2, int pinPIR) {
	this->pinLR = pinLR;
	this->pinLDIST1 = pinLDIST1;
	this->pinLDIST2 = pinLDIST2;
	this->pinPIR = pinPIR;
}

void GateTask::init() {
	LR = new LedLazy(pinLR);
	LR->switchOff();
	LDIST1 = new Led(pinLDIST1);
	LDIST1->switchOff();
	LDIST2 = new Led(pinLDIST2);
	LDIST2->switchOff();
	PIR = new PassiveInfraRed(pinPIR);
  state = WAITING;
}

void GateTask::tick() {
	switch (state) {
		case WAITING:
       if (Serial.available() && Serial.read() == "APRI" && !openingRequest) {
          openingRequest = true;
          state = OPENING;
       }
		case OPENING:
       initialTime = millis();
       LR->switchOn();
       while (millis() - initialTime < TIMEOUT && !autoReady) {
          if (PIR->isPresent()){
              autoReady = true;
              state = CAR;
          }
       }
       state = CLOSING;
		case CLOSING:
       autoReady = false;
       openingRequest = false;
       parcked = false;
       LR->switchOff();
       state = WAITING;
       
		case CAR:
       if (parked) {
          state = CLOSING;
       }
	  }
}
