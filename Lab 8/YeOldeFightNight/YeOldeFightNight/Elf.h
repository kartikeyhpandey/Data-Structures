#pragma once
#include "IRace.h"
class Elf  : IRace
{

public:
	Elf() : IRace(3,1,1,3)
	{
		race = "Elf";
	}
    virtual ~Elf() {}

};