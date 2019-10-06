// CardGameEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\CardGame\CardGame.h"

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
