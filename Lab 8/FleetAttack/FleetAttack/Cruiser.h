#pragma once
#include "Iship.h"
class Cruiser :
    public Iship
{
public:
    Cruiser(IRace* race) : Iship(race)
    {
        m_dmgPerGun = 6;
        m_hull = 6;
        m_numberGuns = 2;
    }
    virtual ~Cruiser();

    virtual int GetHullPoints() override
    {
        int retVal = m_hull + m_race->GetHullPointMods();
        return retVal;
    }

private:
    Cruiser();

};

