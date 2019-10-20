// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CARDGAME_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CARDGAME_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CARDGAME_EXPORTS
#define CARDGAME_API __declspec(dllexport)
#else
#define CARDGAME_API __declspec(dllimport)
#endif

#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;

class CARDGAME_API Card
{
public:
	Card(){}
	Card(int val, string suit) : cardVal(val),cardSuit(suit){
	}
	Card(string suit, int val) : cardSuit(suit), cardVal(val) {
	}

	void SetSuit(string s) {		//Can set the suit using this
		cardSuit = s;
	}

	void SetVal(int i) {			//Can set the card value using this
		cardVal = i;
	}

	string GetSuit() {				//Returns the suit of the card
		return cardSuit;
	}

	int GetVal() {					//Returns the value of the card
		return cardVal;
	}

private:
	string cardSuit;
	int cardVal;

};

class CARDGAME_API Person
{
public:
	Person() {
	}
	Person(string name) : m_name(name)
	{

	}

	std::string GetName() const
	{
		return m_name;
	}

	void View(); //Look at the cards in your hand

	void ViewStack(); //Outputs the player's stack

	void CardToStack(int pos); //Checks to add a card to the stack

	bool AddCard(Card* c); //Adds the card to the player's hand

	void DeleteCard(int pos); //Deletes the card from the player's hand

	bool HandSize(); //Determines if the players hand size is less than or equal to 6

	bool EndTurnCheck(); //Determines if the player has more than 5 cards at the end of their turn

	Card* GetTopStack(); //Checks the top card of the final stack

	Card* GetCardInHand(int i); //Returns the card in hand at the specific index

	int GetNumCards();

	friend class Game;
	friend class Deck;

private:
	string m_name;
	stack<Card*> stackOfCards;
	vector<Card*> playerHand;

};

class CARDGAME_API Deck
{
public:
	Deck();
	~Deck();

	Card* DrawCard();
	int GetSize();
	int faces[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	string suits[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	friend class Game;
	friend class Person;

private:
	queue<Card*> masterDeck; //This is where players will draw from
};

class CARDGAME_API Game
{
public:
	Game();
	~Game();

	void CardToPile(int pos); //Discard a card into the pile

	void RedrawHand(Person* person);

	friend class Person;

	Person* player1;
	Person* player2;
	Person* currentPlayer;

	Deck* deck;

private:

};
