// Lab01EXE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\Lab01DLL\Lab01DLL.h"


int main()
{
	Deck deck;

	Card card1 = deck.GetCard(1);
	Card card2 = deck.GetCard(16);


    return 0;
}

