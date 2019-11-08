#include "CharacterFactory.h"

#include "Cleric.h"
#include "Rogue.h"
#include "Wizard.h"
#include "Fighter.h"

ICharacter* CharacterFactory::CreateCharacter(std::string classType, IRace* race)
{
	ICharacter* theCharacter = nullptr;

	if (classType == "Cleric") {
		theCharacter = new Cleric(race);
	}
	else if (classType == "Rogue") {
		theCharacter = new Rogue(race);
	}
	else if (classType == "Wizard") {
		theCharacter = new Wizard(race);
	}
	else {
		theCharacter = new Fighter(race);
	}

	return theCharacter;
}