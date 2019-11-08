#pragma once
#include "IRace.h"

class Dwarf  : IRace
{

public:
	Dwarf() : IRace(2,2,1,0)
	{
		race = "Dwarf";
	}
    virtual ~Dwarf() {}

};