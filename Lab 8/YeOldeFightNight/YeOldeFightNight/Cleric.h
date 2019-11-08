#pragma once
#include "ICharacter.h"

class Cleric:
	public ICharacter
{
public:
	Cleric(IRace* race) : ICharacter(race)
	{
		m_hitPoints = 12;
		m_hitBonus = 2;
		m_AC = 11;
		m_initiative = 1;
		m_damage = 2;
		m_canHeal = true;
		m_multiAttack = false;
		m_class = "Cleric";
		m_race = race;
	}

	virtual ~Cleric();

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
	Cleric();
};

