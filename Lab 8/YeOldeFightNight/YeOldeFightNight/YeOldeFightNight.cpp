#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Party.h"
#include "CharacterFactory.h"
#include "Elf.h"
#include "Dwarf.h"
#include "Human.h"
#include "Halfling.h"
#include "ICharacter.h"
#include "IRace.h"
#include "Rogue.h"
#include "Cleric.h"
#include "Wizard.h"
#include "Fighter.h"

using namespace std;

int RollDice() 
{
	return rand() % 20 + 1;
}
int main()
{

	// seed the random number generator
	srand(time(NULL));

	cout << "doth shan't play game, Patrick Olekas!" << endl;

	// Game Setup
	Party p1;
	Party p2;
	CharacterFactory cFactory;
	vector<ICharacter*> party1Characters;
	vector<ICharacter*> party2Characters;
	int partyTurn;
	int turn = 1;
	int attack;
	int damage;
	string input;

	IRace* elf = (IRace*) new Elf();
	IRace* dwarf = (IRace*) new Dwarf();
	IRace* half = (IRace*) new Halfling();
	IRace* human = (IRace*) new Human();

	ICharacter* character = nullptr;
	character = cFactory.CreateCharacter("Fighter", elf);
	party1Characters.push_back(character);
	p1.AddMember(character);
	character = cFactory.CreateCharacter("Cleric", dwarf);
	party1Characters.push_back(character);
	p1.AddMember(character);
	character = cFactory.CreateCharacter("Rogue", half);
	party1Characters.push_back(character);
	p1.AddMember(character);
	character = cFactory.CreateCharacter("Wizard", human);
	party1Characters.push_back(character);
	p1.AddMember(character);


	character = cFactory.CreateCharacter("Fighter", elf);
	party2Characters.push_back(character);
	p2.AddMember(character);
	character = cFactory.CreateCharacter("Wizard", half);
	party2Characters.push_back(character);
	p2.AddMember(character);
	character = cFactory.CreateCharacter("Rogue", human);
	party2Characters.push_back(character);
	p2.AddMember(character);
	character = cFactory.CreateCharacter("Cleric", dwarf);
	party2Characters.push_back(character);
	p2.AddMember(character);

	if (p1.TotalInt() > p2.TotalInt())
	{
		partyTurn = 1;
	}
	else
	{
		partyTurn = 2;
	}

	// Game Loop
	while ((p1.PartyDead() == 0) && (p2.PartyDead() == 0))
	{
		cout << "\nTurn " << turn << ":\n" << endl;

		if (partyTurn == 1)
		{
			cout << "\nParty 1's Turn: \n" << endl;

			p1.GetPartyInfo();

			cout << "\nEnter any key to continue: \n";
			cin >> input;

			for (int i = 0; i < party1Characters.size(); ++i)
			{
				attack = p1.GetCharacter(i)->GetHitBonus() + RollDice();
				if (p1.GetCharacter(i)->CanHeal() && p1.GetCharacter(0)->GetHitPoints() < 10)
				{
					p1.GetCharacter(0)->AddHitPoints(3);
					cout << "\nThe cleric healed the first member of the party for 3 hp\n" << endl;
				}
				else if (attack > p2.GetCharacter(0)->GetArmorClass() && p2.size() > 0)
				{
					if ((p1.GetCharacter(i)->CanMultiAttack()) && (p2.size() > 1)) //maybe p2
					{
						cout << "\nThe wizard attacked two people on the other team!\n" << endl;
						p2.GetCharacter(0)->TakeHitPoints(p1.GetCharacter(i)->GetDamage());
						p2.GetCharacter(1)->TakeHitPoints(p1.GetCharacter(i)->GetDamage());
					}
					else
					{
						p2.GetCharacter(0)->TakeHitPoints(p1.GetCharacter(i)->GetDamage());
						cout << "\nThe " << p1.GetCharacter(i)->GetRace() << " " << p1.GetCharacter(i)->GetClass() << " attacked the " << p2.GetCharacter(0)->GetRace() << " " << p2.GetCharacter(0)->GetClass() << endl << endl;
					}

					cout << "Opponent Team's stats:" << endl;
					p2.GetPartyInfo();

					if (p2.DeadMember())
					{
						cout << "\nCongratulations! You managed to kill an enemy!\n" << endl;
						if (party2Characters.size() == 1)
						{
							party2Characters.clear();
							break;
						}
						else {
							party2Characters.resize(party2Characters.size() - 1);
						}
					}
				}
				else if (attack < p2.GetCharacter(0)->GetArmorClass()) {
				cout << "\nParty 1's team member missed their attack!\n" << endl;
				}
			}

			cout << "\nEnter any key to continue: \n";
			cin >> input;

			partyTurn += 1;
		}
		else
		{
			cout << "\nParty 2's Turn: \n" << endl;

			p2.GetPartyInfo();

			cout << "\nEnter any key to continue: \n";
			cin >> input;

			for (int i = 0; i < party2Characters.size(); ++i)
			{
				attack = p2.GetCharacter(i)->GetHitBonus() + RollDice();
				if (p2.GetCharacter(i)->CanHeal() && p2.GetCharacter(0)->GetHitPoints() < 10)
				{
					p2.GetCharacter(0)->AddHitPoints(3);

					cout << "\nThe cleric healed the first member of the party for 3 hp\n" << endl;
				}
				else if (attack > p1.GetCharacter(0)->GetArmorClass() && p1.size() > 0)
				{
					if ((p2.GetCharacter(i)->CanMultiAttack()) && (p1.size() > 1))
					{
						cout << "\nThe wizard attacked two people on the other team!\n" << endl;
						p1.GetCharacter(0)->TakeHitPoints(p2.GetCharacter(i)->GetDamage());
						p1.GetCharacter(1)->TakeHitPoints(p2.GetCharacter(i)->GetDamage());
					}
					else
					{
						p1.GetCharacter(0)->TakeHitPoints(p2.GetCharacter(i)->GetDamage());
						cout << "\nThe " << p2.GetCharacter(i)->GetRace() << " " << p2.GetCharacter(i)->GetClass() << " attacked the " << p1.GetCharacter(0)->GetRace() << " " << p1.GetCharacter(0)->GetClass() << endl << endl;
					}
					cout << "Opponent Team's stats:" << endl;

					p1.GetPartyInfo();

					if (p1.DeadMember())
					{
						cout << "\nCongratulations! You managed to kill an enemy!\n" << endl;
						if (party1Characters.size() == 1)
						{
							party1Characters.clear();
							break;
						}
						else {
							party1Characters.resize(party1Characters.size() - 1);
						}
					}
					
				}
				else if (attack < p1.GetCharacter(0)->GetArmorClass()) {
					cout << "\nParty 2's team member missed their attack!\n" << endl;
				}
			}

			cout << "\nEnter any key to continue: \n";
			cin >> input;

			partyTurn -= 1;
		}
		++turn;
	}
	if (p1.PartyDead())
	{
		cout << "Congratulations, Party 2 won the game!" << endl;
	}
	else if (p2.PartyDead())
	{
		cout << "Congratulations, Party 1 won the game!" << endl;
	}
	else
	{
		cout << "How did you get here?" << endl;
	}
}