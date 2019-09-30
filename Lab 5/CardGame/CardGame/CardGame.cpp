// CardGame.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "CardGame.h"


#include <vector>
#include <string>
#include <stdexcept>
#include <iostream> 
#include <stack> 
#include <queue>
#include <stdlib.h>

Card::Card(int suit, int rank) {
	this->suit = suit;
	this->rank = rank;
}

Card::~Card() {}

string Card::getCardSuit() {
	switch (this->suit) {
	case 1: return "H";
	case 2: return "D";
	case 3: return "S";
	case 4: return "C";
	default: return " ";
	}
}

string Card::getCardRank() {
	string str = "";
	switch (rank) {
	case 1: str = " A"; break;
	case 2: str = " 2"; break;
	case 3: str = " 3"; break;
	case 4: str = " 4"; break;
	case 5: str = " 5"; break;
	case 6: str = " 6"; break;
	case 7: str = " 7"; break;
	case 8: str = " 8"; break;
	case 9: str = " 9"; break;
	case 10: str = "10"; break;
	case 11: str = " J"; break;
	case 12: str = " Q"; break;
	case 13: str = " K"; break;
	default: str = "  "; break;
	}
	return str;
}

int Card::getRank() {
	return rank;
}

int Card::getSuit() {
	return suit;
}

string Card::toStr() {
	return suit + "," + rank;
}

Deck::Deck() {
	seed = rand();
	this->reload();
}

Deck::Deck(int seed) {
	this->seed = seed;
	this->reload();
}

Deck::Deck(queue <Card*> d) {
	deck = queue <Card*>(d);

}

Deck::~Deck() {
	while (!deck.empty()) {
		delete deck.front(); //deletes card
		deck.pop(); //deletes pointer
	}
}

Card* Deck::draw() { //draws top card and pops it
	Card* temp = deck.back();// front();
	deck.pop();
	return temp;
}

void Deck::load(Card* x) { //adds card to queue
	deck.push(x);
}

void Deck::reload() { //clears and loads all 52 possible cards into deck
	srand(seed);
	Card* arr[52];
	int n = 0;
	for (int k = 1; k <= 4; k++) { //create all cards
		for (int g = 1; g <= 13; g++) {
			Card* c = new Card(k, g);
			arr[n++] = c;
		}
	}
	for (int k = 0; k <= 300; k++) {//shuffle
		int r1 = rand() % 52;
		int r2 = rand() % 52;

		Card* temp = arr[r1];
		arr[r1] = arr[r2];
		arr[r2] = temp;
	}
	for (int k = 0; k < 52; k++) {
		deck.push(arr[k]);
	}
}

int Deck::cardsInDeck() { //total cards in deck
	return deck.size();
}

string Deck::toStr() {
	string str = "";
	queue <Card*> temp = deck;
	while (!temp.empty()) {
		str += "\n" + temp.front()->toStr();
		temp.pop();
	}
	return str;
}

Player::Player() {}
Player::~Player() {}

int Player::cardsinHand() { //total cards in the player's hand
	int count = 0;
	for (int k = 0; k < 6; k++) {
		if (hand[k] == nullptr)
			count++;
	}
	return count;
}

bool Player::add(Card* c) { //adds card, returns false if cannot add
	int n = this->place();
	if (n >= 0) {
		hand[n] = c;
		return true;
	}
	return false;
}

int Player::place() { //finds first avaliable spot to put a card
	for (int k = 0; k < 6; k++) {
		if (hand[k] == nullptr)
			return k;
	}
	return -1;
}

bool Player::play(int i) { //card leaves player hand
	Card* c = hand[i];
	if (this->topStack()->getRank() != c->getRank() - 1) {
		cout << "This card cannot be stacked";
		return false;
	}
	if (hand[i] == nullptr) {
		cout << "There is no card at this spot in the hand";
		return false;
	}
	hand[i] = nullptr;
	masterStack.push(c);
	return true;
}

Card* Player::discard(int i) { //deletes a card from the hand
	Card* c = hand[i];
	hand[i] = nullptr;
	return c;
}

Card* Player::preview(int i) { //shows a card in hand
	Card* c = hand[i];
	return c;
}

bool Player::endTurn() { //tests if player can end their turn, also implements rule 5
	if (this->cardsinHand() > 5)
		return false;
	return true;
}

void Player::showCards() {
	for (int g = 0; g < 5; g++) { //line
		for (int k = 0; k < 6; k++) { //card
			Card* c = hand[k];
			string r = " ";
			string s = " ";
			if (c != nullptr) {
				string r = c->getCardRank();
				string s = c->getCardSuit();
			}
			switch (g) {
			case 0: cout << "[      ]  "; break;
			case 1: cout << "[   " + r + "   ]  "; break;
			case 2: cout << "[   " + s + "   ]  "; break;
			case 3: cout << "[      ]  "; break;
			case 4: cout << "[#Card" + to_string(k) + "#]  "; break;
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

string Player::testHand() {
	string str = "";
	for (int k = 0; k < 6; k++) {
		str += hand[k]->getCardRank() + ",";
		str += hand[k]->getCardSuit() + "/";
	}
	return str;
}

Card* Player::topStack() {
	return masterStack.top();
}

Game::Game() {}

Game::~Game() {}

bool Game::endGame() { //ends the game, returns false if cannot end
	Card* p1 = player1->topStack();
	Card* p2 = player2->topStack();
	if (p1->getRank() == 13 || p2->getRank() == 13)
		return true;
	return false;
}

void Game::resetHand() { //implemetes rule 6
	Player* p = nullptr;
	switch (turn) {
	case 1: p = player1;
	case 2: p = player2;
	}

	for (int k = 0; k < 6; k++) { //discard entire hand
		Card* c = p->discard(k);
		if (c != nullptr)
			deck->load(c);
	}

	for (int k = 0; k < 5; k++) //draw 5 cards
		p->add(deck->draw());

	switch (turn) {
	case 1: player1 = p;
	case 2: player2 = p;
	}
}

bool Game::drawCard() { //card from deck to hand, false if cannot add
	Player* p = nullptr;
	switch (turn) {
	case 1: p = player1;
	case 2: p = player2;
	}
	if (p->cardsinHand() > 6)
		return false;

	p->add(deck->draw());

	switch (turn) {
	case 1: player1 = p;
	case 2: player2 = p;
	}

	return true;
}

bool Game::playCard(int i) { //play card from hand to stack, false if cannot play
	Player* p = nullptr;
	switch (turn) {
	case 1: p = player1;
	case 2: p = player2;
	}

	bool tf = p->play(i);

	switch (turn) {
	case 1: player1 = p;
	case 2: player2 = p;
	}

	return tf;
}

void Game::status() { //prints stack and hand of current player
	Player* p = nullptr;
	switch (turn) {
	case 1: p = player1;
	case 2: p = player2;
	}

	cout << "It is Player " << turn << "'s turn\n";
	p->showCards();
	cout << "Top of Stack Status: " << p->topStack();
}

bool Game::endTurn() { //ends current players turn, false if cannot end
	Player* p = nullptr;
	switch (turn) {
	case 1: p = player1;
	case 2: p = player2;
	}

	if (p->cardsinHand() > 5) {
		cout << "There are too many cards in your hand, discard";
		return false;
	}

	switch (turn) {
	case 1: turn = 2;
	case 2: turn = 1;
	}
	return true;
}

int Game::getTurn() {
	return turn;
}

int main() {
	Game g; //starts game
	bool end_game = false;
	cout << "13: a Solitare Knock Off\n";
	cout << "Input actions as displayed, i.e. 'Draw'";
	g.resetHand();

	while (!end_game) {
		//temp vars
		string input;
		int input_num;
		bool ans;
		bool cont = true;
		bool cont1 = true;
		bool cont2 = true;
		bool pass = true;
		//beginning of turn
		g.status();
		//redraw hand?
		cout << "You do you want to redraw your hand? [Y or N]: ";
		while (cont) { //while input is input incorrectly
			cout << endl;
			cin >> input;
			if (input == "Y" || input == "y")
				ans = true; cont = false; cont2 = false;
			if (input == "N" || input == "n")
				ans = false; cont = false;
			cout << "Input not interpertable, please re-input: ";
		}
		cout << endl;
		g.status();
		// middle of turn actions
		while (cont2) {//while turn is still active
			cont1 = true;
			cout << "Actions: [Draw, Play, Discard, End Turn]\n";
			while (cont1) { //choses which action or if typed wrong
				cin >> input;
				if (input == "Draw" || input == "draw") {
					pass = g.drawCard();
					cont1 = false;
					if (!pass)
						cout << "Can't draw card\n";
				}
				else if (input == "Play" || input == "play") {
					cout << "Which Card #?: ";
					cin >> input_num;
					pass = g.playCard(input_num);
					cont1 = false;
					if (!pass)
						cout << "Can't play card on stack\n";
				}
				else if (input == "Discard" || input == "discard") {
					pass = g.drawCard();
					cont1 = false;
					if (!pass)
						cout << "Can't discard card\n";
				}
				else if (input == "End Turn" || input == "end turn") {
					pass = g.drawCard();
					cont1 = false;
					if (!pass)
						cout << "Can't end turn\n";
					else
						cont = false;
				}
				else {
					cout << "Command not understood, check spelling.";
				}
			}
			g.status();
		}

		if (g.endGame()) {//ends game and exits loop
			end_game = true;
			cout << "Player " + to_string(g.getTurn()) + " won!";
		}

		g.endTurn();
	}
	return 0;
}