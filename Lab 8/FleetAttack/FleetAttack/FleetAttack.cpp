// FleetAttack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fleet.h"
#include "Iship.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "ShipFactory.h"
#include "Zerg.h"
#include "IRace.h"
#include "FleetAttack.h"

int main()
{

	Fleet<double> numberBox;
	Fleet<std::string> nameBox;
    Fleet<Iship*> fleet1;

	numberBox.setFlagShip(6.5);
	nameBox.setFlagShip("Hello");

	ShipFactory shipFactory;
	IRace* race = (IRace *) new Zerg();

	Iship* val = shipFactory.CreateShip(ShipFactory::BattleShipType, race);

	BattleShip* battleShip = dynamic_cast<BattleShip*>(val);

    fleet1.setFlagShip(battleShip);

    val = shipFactory.CreateShip(ShipFactory::CruiserType, race);

    Cruiser* cruiser = dynamic_cast<Cruiser*>(val);

    fleet1.addFlotilla(cruiser);

    std::vector<Iship*> flotilla = fleet1.getFlotilla();

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
