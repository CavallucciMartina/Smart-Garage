#ifndef __PASSIVE_INFRA_RED__
#define __PASSIVE_INFRA_RED__

#include "Presence.h"

class PassiveInfraRed: public Presence { 

	public:
	PassiveInfraRed(int pin);
	bool isPresent();
	
	protected:
	int pin;  
};

#endif
