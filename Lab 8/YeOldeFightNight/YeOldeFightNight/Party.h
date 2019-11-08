#pragma once
#include <vector>
#include "ICharacter.h"

class Party
{
public:
	Party();

	void AddMember(ICharacter* Character);

	bool PartyDead();

	void GetPartyInfo();

	int TotalInt();

	bool DeadMember();

	int size() { return m_party.size(); }

	std::vector<ICharacter*> GetMembers() { return m_party; }

	ICharacter* GetCharacter(int n) { return m_party[n]; }

private:
	std::vector<ICharacter*> m_party;
};
