#include "PassiveInfraRed.h"
#include "Arduino.h"

PassiveInfraRed::PassiveInfraRed(int pin){
	this->pin = pin;
	pinMode(pin,INPUT);
}

bool PassiveInfraRed::isPresent(){
  return  digitalRead(pin) == HIGH;
}
