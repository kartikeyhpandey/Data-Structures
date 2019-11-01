#pragma once

class IRace
{
public:
	IRace(int HitPointMod, int ArmorClassMod, int HitBonusMod, int InitiativeBonus) :m_HitPointMod(HitPointMod),
	 m_ArmorClassMod(ArmorClassMod), m_HitBonusMod(HitBonusMod), m_InitiativeBonus(InitiativeBonus){};
	~IRace();

	virtual int getHitPointMod() = 0;


protected:
	int m_HitPointMod;
	int m_ArmorClassMod;
	int m_HitBonusMod;
	int m_InitiativeBonus;

};