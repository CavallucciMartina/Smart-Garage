#include "GateTask.h"
#include "Arduino.h"
#include "GlobalVar.h"

GateTask::GateTask(int pinLR, int pinPIR) {
	this->pinLR = pinLR;
	this->pinPIR = pinPIR;
  openingRequest = false;
  autoReady = false;
  parked = false;
  wall = false;
}

void GateTask::init() {
	LR = new LedLazy(pinLR);
	LR->switchOff();
	PIR = new PassiveInfraRed(pinPIR);
  state = WAITING;
}

void GateTask::tick() {
	switch (state) {
    
		case WAITING:
       if (Serial.available() && String("OPEN").equals(Serial.readString()) && !openingRequest) {
          openingRequest = true;
          state = OPENING;
       }
       break;
       
		case OPENING:
       LR->switchOn();
       initialTime = millis();
       while (millis() - initialTime < TIMEOUT && !autoReady) {
          if (PIR->isPresent()){
              autoReady = true;
              state = CAR;
          }
       }
       if (millis() - initialTime > TIMEOUT || !autoReady) {
          state = CLOSING;
       }
       break;
       
		case CLOSING:
       autoReady = false;
       openingRequest = false;
       parked = false;
       wall = false;
       LR->switchOff();
       state = WAITING;
       break;
       
		case CAR:
       if (parked) {
          state = CLOSING;
       }
       break;
	  }
}
