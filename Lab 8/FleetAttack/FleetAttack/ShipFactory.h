#pragma once

#include "IRace.h"
#include "Iship.h"

class ShipFactory
{
public:
	ShipFactory() {}

	enum enumOfTypeShip { BattleShipType, CruiserType };

	Iship* CreateShip(enumOfTypeShip, IRace* race);

    virtual ~ShipFactory() {}
};

