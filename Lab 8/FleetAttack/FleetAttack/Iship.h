#pragma once

#include "IRace.h"
class Iship
{
public:

    Iship(IRace* race) : m_hull(0), m_numberGuns(0), m_dmgPerGun(0), m_race(race)
    {

    }

	virtual int GetHullPoints() = 0;

    virtual ~Iship() {}

protected:
	int m_hull;
	int m_numberGuns;
	int m_dmgPerGun;
	IRace* m_race;

};

