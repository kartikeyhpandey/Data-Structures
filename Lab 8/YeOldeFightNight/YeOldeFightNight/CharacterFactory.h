#pragma once

#include "IRace.h"
#include "ICharacter.h"

class CharacterFactory
{
public:
	CharacterFactory() {}

	ICharacter* CreateCharacter(std::string classType, IRace* race);

	virtual ~CharacterFactory() {}
};

