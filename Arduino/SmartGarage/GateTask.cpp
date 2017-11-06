#include "gateTask.h"

GateTask::GateTask(int pinLR, int pinLDIST1, int pinLDIST2, int pinPIR) {
	this->pinLR = pinLR;
	this->pinLDIST1 = pinLDIST1;
	this->pinLDIST2 = pinLDIST2;
	this->pinPIR = pinPIR;
}

void GateTask::init() {
	LR = new Led(pinLR);
	LR->switchOff();
	LDIST1 = new Led(pinLDIST1);
	LDIST1->switchOff();
	LDIST2 = new Led(pinLDIST2);
	LDIST2->switchOff();
	PIR = new PassiveInfraRed(pinPIR);
}

void GateTask::tick() {
	switch (state) {
		case WAITING:
    ;
		case OPENING:
    ;
		case CLOSING:
    ;
		case CAR:
    ;
	}
}
