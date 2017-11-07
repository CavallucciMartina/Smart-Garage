#include "gateTask.h"
#include "Arduino.h"
#include "GlobalVar.h"

GateTask::GateTask(int pinLR, int pinLDIST1, int pinLDIST2, int pinPIR) {
	this->pinLR = pinLR;
	this->pinLDIST1 = pinLDIST1;
	this->pinLDIST2 = pinLDIST2;
	this->pinPIR = pinPIR;
  openingRequest = false;
  autoReady = false;
  parked = false;
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
       if (Serial.available() && Serial.readString() == "APRI" && !openingRequest) {
          openingRequest = true;
          state = OPENING;
       }
       Serial.println(state);
		case OPENING:
       initialTime = millis();
       LR->switchOn();
       while (millis() - initialTime < TIMEOUT && !autoReady) {
          if (PIR->isPresent()){
              autoReady = true;
              state = CAR;
          }
       }
       if (millis() - initialTime > TIMEOUT || !autoReady) {
          state = CLOSING;
       }
       Serial.println(state);
		case CLOSING:
       autoReady = false;
       openingRequest = false;
       parked = false;
       LR->switchOff();
       state = WAITING;
       Serial.println(state);
		case CAR:
       if (parked) {
          delay(5000);
          //state = CLOSING;
       }
       Serial.println(state);
	  }
}
