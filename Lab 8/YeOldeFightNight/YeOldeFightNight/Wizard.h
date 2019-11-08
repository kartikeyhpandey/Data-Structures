#pragma once
#include "ICharacter.h"

class Wizard :
	public ICharacter
{
public:
	Wizard(IRace* race) : ICharacter(race)
	{
		m_hitPoints = 10;
		m_hitBonus = 1;
		m_AC = 10;
		m_initiative = 1;
		m_damage = 2;
		m_canHeal = false;
		m_multiAttack = true;
		m_class = "Wizard";
		m_race = race;
	}

	virtual ~Wizard();

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
	Wizard();
};

