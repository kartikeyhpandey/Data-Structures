#pragma once
#include <string>

class IRace
{
public:
	IRace(int HitPointMod, int ArmorClassMod, int HitBonusMod, int InitiativeBonus) :m_HitPointMod(HitPointMod),
	 m_ArmorClassMod(ArmorClassMod), m_HitBonusMod(HitBonusMod), m_InitiativeBonus(InitiativeBonus){};
	~IRace() {}

	virtual int getHitPointMod() { return m_HitPointMod; };

	virtual int getArmorClassMod() { return m_ArmorClassMod; };

	virtual int getHitBonusMod() { return m_HitBonusMod; };

	virtual int getInitiativeBonus() { return m_InitiativeBonus; };

	std::string GetRaceName() { return race; }

protected:
	int m_HitPointMod;
	int m_ArmorClassMod;
	int m_HitBonusMod;
	int m_InitiativeBonus;
	std::string race;

};