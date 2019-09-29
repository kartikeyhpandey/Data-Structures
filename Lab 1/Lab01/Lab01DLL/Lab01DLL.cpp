// Lab01DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Lab01DLL.h"


// This is the constructor of a class that has been exported.
// see Lab01DLL.h for the class definition
Card::Card(suit_t suit, int rank): m_suit(suit), m_rank(rank), m_dealt(false)
{
    
}


Deck::Deck()
{
	init_deck();
}

Card Deck::GetCard(int index)
{
	return m_deck[index];
}

Card Deck::GetCard(suit_t suit, int rank)
{
	//TODO: Implement me !!
	for (int k = 0; k <= size(m_deck); k++) {
		if (m_deck.at(k).GetSuit() == suit) {
			if (m_deck.at(k).GetRank() == rank) {
				return m_deck[k]; //returning the card
			}
		}
	} //searching for the card
	throw "NIY";
}

/**
* Initialize the deck so that all cards exist, and are not yet dealt.
*/
void Deck::init_deck() 
{
	int pos = 0;
	for (int s = 0; s < 4; s++) {
		for (int rank = 1; rank <= 13; rank++) 
		{
			m_deck.push_back(Card((suit_t)s, rank));
			pos++;
		}
	}
}

BlackJackHand::BlackJackHand()
{
	
}

void BlackJackHand::AddCard(Card c)
{
	//TODO
	m_hand.push_back(c); //adding the card to the vector
}

int BlackJackHand::ScoreHand()
{
	//TODO
	int total = 0; //variable to mantain the score tally
	int rank = 0;

	for (int k = 0; k < m_hand.size(); k++) {
		
		rank = m_hand.at(k).GetRank(); //getting rank of the card
		if (2 <= rank && rank <= 10) {
			total += rank; //for cards other than aces and face cards, adding the numerical value of the card
		}
		else if (11 <= rank && rank <= 13) {
			total += 10; //for face cards, adding 10
		}
		else if (rank == 1) {
			if (total + 11 > 21)
				total += 1; //if the total exceeds 21, adding 1
			else
				total += 11; //if the total isn't exceeding 21, adding 11
		}
	} // traversing through the hand

	if (total > 21) {
		return -1; //returning -1 if the score is above 21 for bust
	}
	else {
		return total; //returning total score
	}
}


