#include "Party.h"
#include <iostream>

using namespace std;

Party::Party()
{
	
}

void Party::GetPartyInfo() 
{
	if (m_party.empty()){}
	else
	{
		for (int i = 0; i < m_party.size(); ++i)
		{
			cout << "Character " << i + 1 << ": " << m_party[i]->GetRace() << " " << m_party[i]->GetClass() << endl;
			cout << "HP: " << m_party[i]->GetHitPoints() << endl;
			cout << "AC: " << m_party[i]->GetArmorClass() << endl;
			cout << "Hit Bonus: " << m_party[i]->GetHitBonus() << endl;
		}
	}
}
bool Party::PartyDead(){
	if(m_party.size() == 0)
	{
		return true;
	}
	return false;
}
void Party::AddMember(ICharacter* character)
{
	m_party.push_back(character);
}

int Party::TotalInt()
{
	int totalInt = 0;
	for (int i = 0; i < m_party.size(); ++i)
	{
		totalInt = totalInt + m_party[i]->GetInitiative();
	}
	return totalInt;
}

bool Party::DeadMember()
{
	bool dead = false;
	for (int i = 0; i < m_party.size(); ++i)
	{
		if (m_party[i]->GetHitPoints() <= 0 && m_party.size() >= 1)
		{
			dead = true;
			m_party.erase(m_party.begin());
		}
		else if (m_party[i]->GetHitPoints() <= 0)
		{
			dead = true;
			m_party.clear();
		}
	}
	return dead;
}