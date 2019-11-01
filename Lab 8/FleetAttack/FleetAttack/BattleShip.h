#pragma once

#include "Iship.h"
#include "IRace.h"

class BattleShip : public Iship
{
public:

	BattleShip(IRace* race) : Iship(race)
	{
        m_dmgPerGun = 10;
        m_hull = 10;
        m_numberGuns = 2;
	}

    ~BattleShip() {}

	virtual int GetHullPoints() override
	{
		int retVal = m_hull + m_race->GetHullPointMods();
		return retVal;
	}

private :
    BattleShip();

};

