// CardGame.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "CardGame.h"

CARDGAME_API Card* Person::GetTopStack()
{
	if(stackOfCards.empty())
	{
		return nullptr;
	}
	return stackOfCards.top();
}

CARDGAME_API bool Person::HandSize()
{
	if (playerHand.size() < 6) return true;
	else return false;
}

CARDGAME_API bool Person::EndTurnCheck()
{
	if (playerHand.size() == 6) return true;
	else return false;
}

CARDGAME_API bool Person::AddCard(Card* c)
{
	if (this->HandSize()) {
		playerHand.push_back(c);
		return true;
	}
	else
	{
		cout << "Error: Your hand size cannot exceed 6 cards" << endl;
		return false;
	}
}

CARDGAME_API Card* Person::GetCardInHand(int i)
{
	return playerHand[i];
}

CARDGAME_API void Person::DeleteCard(int pos)
{
	Card* c = GetCardInHand(pos);
	playerHand.erase(playerHand.begin() + pos);
}

CARDGAME_API void Person::CardToStack(int pos) {
	Card* c = GetCardInHand(pos);
	if (stackOfCards.empty()){
		if (c->GetVal() == 1) {
			stackOfCards.push(c);
			playerHand.erase(playerHand.begin() + pos);
		}
		else {
			cout << "Error, you cannot add cards out of order to your stack." << endl;
		}
	}
	else if (c->GetVal() == stackOfCards.top()->GetVal() + 1) {
		stackOfCards.push(c);
		playerHand.erase(playerHand.begin() + pos);
	}
	else {
		cout << "Error, you cannot add cards out of order to your stack." << endl;
	}
}

CARDGAME_API void Person::View() {

	cout << "Cards in Hand: ";
	for (int i = 0; i < playerHand.size(); ++i) {
		cout << playerHand[i]->GetVal() << " ";
	}
	cout << endl;
}

CARDGAME_API void Person::ViewStack()
{
	cout << "Cards in Stack: ";
	stack<Card*> copyStack = stackOfCards;
	while(!copyStack.empty())
	{
		cout << copyStack.top()->GetVal() << " ";
		copyStack.pop();
	}
	cout << endl;
}

CARDGAME_API int Person::GetNumCards()
{
	return playerHand.size();
}

CARDGAME_API Deck::Deck()
{
	for (int i = 0; i < 52; i++)
	{
		
		Card* tmpCard = new Card(faces[i % 13], suits[i % 4]);
		masterDeck.push(tmpCard);
	}
}

CARDGAME_API Deck::~Deck()
{
	while (!masterDeck.empty())
	{
		delete masterDeck.front();
		masterDeck.pop();
	}
}

CARDGAME_API int Deck::GetSize()
{
	return masterDeck.size();
}

CARDGAME_API Card* Deck::DrawCard()
{
	Card* c = masterDeck.front();
	masterDeck.pop();

	return c;
}

CARDGAME_API Game::Game()
{
	// Game setup
	player1 = new Person("Joe");
	player2 = new Person("Mama");

	currentPlayer = player1;

	deck = new Deck();

	for (unsigned int i = 0; i < 10; i++)
	{	
		Card* c = deck->DrawCard();

		if (i % 2)
		{
			player1->AddCard(c);
		}
		else 
		{
			player2->AddCard(c);
		}
	}
}
CARDGAME_API Game::~Game() {
	delete player1;
	delete player2;
	delete deck;
}

CARDGAME_API void Game::CardToPile(int pos) {
	Card* c = currentPlayer->GetCardInHand(pos);
	if (pos > 6) {
		cout << "Error: Position is out of bounds" << endl;
	}
	else {
		deck->masterDeck.push(c);
		currentPlayer->DeleteCard(pos);
	}
}

CARDGAME_API void Game::RedrawHand(Person* person)
{
	// Remove cards from hand and add to bottom of deck
	for (unsigned int i = person->playerHand.size(); i > 0; i--)
	{
		deck->masterDeck.push(person->playerHand[i-1]);
		person->playerHand.pop_back();
	}

	// Draw 5 cards from the deck
	for (unsigned int j = 0; j < 5; j++)
	{
		person->playerHand.push_back(deck->DrawCard());
	}
}