#pragma once
#include "IRace.h"

class Halfling  : IRace
{

public:
	Halfling() : IRace(1,0,3,2)
	{
		race = "Halfling";
	}
    virtual ~Halfling() {}

};