#include "PassiveInfraRed.h"
#include "Arduino.h"

PassiveInfraRed::PassiveInfraRed(int pin){
	this->pin = pin;
	pinMode(pin,INPUT);
	
	/*
		Eventualmente si può aggiungere un time
		di attesa per permettere allo strumento
		di calibrarsi propriamente.	
	*/
}

bool PassiveInfraRed::isPresent(){
	return digitalRead(pin) == HIGH;
}
