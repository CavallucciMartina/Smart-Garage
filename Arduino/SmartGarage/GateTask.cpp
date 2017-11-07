#include "GateTask.h"
#include "Arduino.h"
#include "GlobalVar.h"

GateTask::GateTask(int pinLR, int pinPIR) {
	this->pinLR = pinLR;
	this->pinPIR = pinPIR;
  openingRequest = false;
  autoReady = false;
  parked = false;
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
       Serial.println("WAITING");
       if (Serial.available() && String("APRI").equals(Serial.readString()) && !openingRequest) {
          openingRequest = true;
          state = OPENING;
       }
       break;
       
		case OPENING:
       Serial.println("OPENING");
       initialTime = millis();
       LR->switchOn();
       while (millis() - initialTime < TIMEOUT && !autoReady) {
          if (PIR->isPresent()){
              autoReady = true;
              state = CAR;
              Serial.println("CAR");
          }
       }
       if (millis() - initialTime > TIMEOUT || !autoReady) {
          state = CLOSING;
       }
       break;
       
		case CLOSING:
       Serial.println("CLOSING");
       autoReady = false;
       openingRequest = false;
       parked = false;
       LR->switchOff();
       state = WAITING;
       break;
       
		case CAR:
		   Serial.println("CAR");
       if (parked) {
          state = CLOSING;
       }
       break;
	  }
}
