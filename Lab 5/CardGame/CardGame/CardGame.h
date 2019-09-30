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



#include <vector>
#include <string>
#include <stdexcept>
#include <iostream> 
#include <stack> 
#include <queue>

using namespace std;

class CARDGAME_API Card {
public:
	Card(int suit, int rank);
	~Card();
	int getRank();
	int getSuit();
	string getCardRank();
	string getCardSuit();
	string toStr();

private:
	int suit;
	int rank;
};


class CARDGAME_API Deck {
public:
	Deck();
	Deck(int seed);
	Deck(queue <Card*> d);
	~Deck();
	Card* draw(); //draws top card and pops it
	void load(Card* x); //adds card to queue
	void reload(); //clears and loads all 52 possible cards into deck
	int cardsInDeck(); //total cards in deck
	string toStr();

private:
	queue <Card*> deck;
	int seed;
};

class CARDGAME_API Player {
public:
	Player();
	~Player();
	int cardsinHand(); //total cards in the player's hand
	bool add(Card* c); //adds card to hand, returns false if cannot add
	bool play(int i); //plays card from hand to stack
	bool endTurn(); //tests if player can end their turn, also implemetns rule 5
	int place(); //finds first avaliable spot to put a card
	Card* preview(int i); //shows a card in hand
	void showCards(); //display hand or stack as string
	string testHand(); //displays hand for testing purposes
	Card* topStack(); //top card of stack
	Card* discard(int i); //outputs a card and deletes from hand

private:
	Card* hand[6]; //player's hand
	stack <Card*> masterStack; //stack the player is building
};

class CARDGAME_API Game {
public:
	Game();
	~Game();
	bool endGame(); //ends the game, returns false if cannot end
	void resetHand(); //implemetes rule 6
	bool drawCard(); //card from deck to hand, false if cannot add
	bool playCard(int i); //play card from hand to stack, false if cannot play
	void status(); //prints stack and hand of current player
	bool endTurn(); //ends current players turn, false if cannot end
	int getTurn(); //gets current player number

private:
	int turn = 1; //keeps track of whos turn it is, 1 - Player 1, 2 - Player 2
	Player* player1;
	Player* player2;
	Deck* deck;
};