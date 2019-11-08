#pragma once
#include "ICharacter.h"

class Fighter :
	public ICharacter
{
public:
	Fighter(IRace* race) : ICharacter(race)
	{
		m_hitPoints = 14;
		m_hitBonus = 1;
		m_AC = 13;
		m_damage = 3;
		m_initiative = 0;
		m_canHeal = false;
		m_multiAttack = false;
		m_class = "Fighter";
		m_race = race;
	}

	virtual ~Fighter();

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
	Fighter();
};

