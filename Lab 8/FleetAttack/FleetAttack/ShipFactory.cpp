#include "ShipFactory.h"

#include "BattleShip.h"
#include "Cruiser.h"

Iship* ShipFactory::CreateShip(enumOfTypeShip enumOfTypeShipType, IRace* race)
{
	Iship* retVal = nullptr;
	if (enumOfTypeShipType == BattleShipType)
	{
		retVal = new BattleShip(race);
	}
    else if (enumOfTypeShipType == CruiserType)
    {
        retVal = new Cruiser(race);
    }

	return retVal;
}
