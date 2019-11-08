#pragma once
#include "IRace.h"
#include <string>

class ICharacter
{
public:
	
	ICharacter(IRace* race) : m_hitPoints(), m_AC(), m_hitBonus(), m_initiative(), m_race(race), m_multiAttack(false), m_class(), m_canHeal(false), m_damage()
	{

	}

	std::string GetClass() { return m_class; }

	std::string GetRace() { return m_race->GetRaceName(); }

	bool CanHeal() { return m_canHeal; }

	bool CanMultiAttack() { return m_multiAttack; }

	void AddHitPoints(int heal) { m_hitPoints = GetHitPoints() + heal - m_race->getHitPointMod(); }

	void TakeHitPoints(int damage) { m_hitPoints = GetHitPoints() - damage - m_race->getHitPointMod(); }

	int GetDamage() { return m_damage; }

	virtual int GetHitPoints() = 0;

	virtual int GetArmorClass() = 0;

	virtual int GetHitBonus() = 0;

	virtual int GetInitiative() = 0;


	~ICharacter() {}

protected: 
	int m_hitPoints;
	int m_AC;
	int m_hitBonus;
	int m_initiative;
	bool m_canHeal;
	bool m_multiAttack;
	int m_damage;
	IRace* m_race;
	std::string m_class;
};

