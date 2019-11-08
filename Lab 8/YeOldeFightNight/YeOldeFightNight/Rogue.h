#pragma once
#include "ICharacter.h"

class Rogue :
	public ICharacter
{
public:
	Rogue(IRace* race) : ICharacter(race)
	{
		m_hitPoints = 11;
		m_hitBonus = 3;
		m_AC = 10;
		m_initiative = 3;
		m_damage = 4;
		m_canHeal = false;
		m_multiAttack = false;
		m_class = "Rogue";
		m_race = race;
	}

	virtual ~Rogue();

	virtual int GetHitPoints() override
	{
		int HP = m_hitPoints + m_race->getHitPointMod();
		return HP;
	}

	virtual int GetArmorClass() override
	{
		int AC = m_AC + m_race->getArmorClassMod();
		return AC;
	}

	virtual int GetHitBonus() override
	{
		int hitBonus = m_hitBonus + m_race->getHitBonusMod();
		return hitBonus;
	}

	virtual int GetInitiative() override
	{
		int initiative = m_initiative + m_race->getInitiativeBonus();
		return initiative;
	}
private:
	Rogue();
};

