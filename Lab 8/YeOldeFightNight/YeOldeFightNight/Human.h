#pragma once
#include "IRace.h"

class Human  : IRace
{

public:
	Human() : IRace(2,1,1,2)
	{
		race = "Human";
	}
    virtual ~Human() {}

};