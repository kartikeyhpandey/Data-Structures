#pragma once
class IRace
{
public:
	IRace(int HullPointMods, int  gunMods, int  dmgPerGunMod) :m_HullPointMods(HullPointMods),
		m_gunMods(gunMods),
		m_dmgPerGunMod(dmgPerGunMod)
	{}

	virtual int GetHullPointMods() { return m_HullPointMods; }

    ~IRace() {}
protected:
	int m_HullPointMods;
	int m_gunMods;
	int m_dmgPerGunMod;
};

