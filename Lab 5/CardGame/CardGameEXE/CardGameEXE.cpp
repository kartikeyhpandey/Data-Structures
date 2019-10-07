// CardGameEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\CardGame\CardGame.h"

int main()
{
	Game game;
	bool isDone = false;

	// Main game loop
	while (!isDone){
		cout << "It is " << game.currentPlayer->GetName() << "'s turn." << endl;
		game.currentPlayer->View();

		string input;
		int input_pos;
		bool cont = true;
		bool cont1 = true;
		bool cont2 = true;

		cout << " You do you want to redraw your hand? [Y or N]: ";
		while (cont) {								//Asks if the player wants to redraw their hand
			cout << endl;
			cin >> input;
			// Convert string to lowercase
			// From: https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
			transform(input.begin(), input.end(), input.begin(), ::tolower);

			// Input handling
			if (input == "y")
			{
				cont = false; 
				cont2 = false;
				game.RedrawHand(game.currentPlayer);

			}
			else if (input == "n")
			{
				cont = false;
			}
			else
			{
				cout << "Input not interpertable, please re-input: ";
			}
		}
			cout << endl;
			while(cont2){				//Actual turn where the user can take actions
				cont1 = true;
				cout << "Actions: [Draw, Play, Discard, End]\n";
				while(cont1){
					cin >> input;
					transform(input.begin(), input.end(), input.begin(), ::tolower);
					if (input == "draw"){
						cont1 = false;
						game.currentPlayer->AddCard(game.deck->DrawCard());
					}
					else if (input == "play")
					{
						cont1 = false;
						cout << "Which card position do you want to play? (Enter card position in hand ex. 1, 4, etc.)" << endl;
						cin >> input_pos;
						game.currentPlayer->CardToStack(input_pos-1);
					}
					else if (input == "discard")
					{
						cont1 = false;
						cout << "Which card position do you want to discard? (Enter card position in hand ex. 1, 4, etc.)" << endl;
						cin >> input_pos;
						game.CardToPile(input_pos-1);
					}
					else if (input == "end")
					{
						cont1 = false;
						cont2 = false;
					}
					else
					{
						cout << "Error: Enter a valid move" << endl;
						cont1 = false;
					}
					game.currentPlayer->View();
					game.currentPlayer->ViewStack();
				}
			}
			// Check to make sure player hands are not greater than 5
			if (game.currentPlayer->EndTurnCheck()){
				cout << "You must discard one card into the pile. Which card do you want to discard? ";
				cin >> input_pos;
				game.CardToPile(input_pos-1);
			}

		// Check for a winner
		if (game.currentPlayer->GetTopStack() != nullptr && game.currentPlayer->GetTopStack()->GetVal() == 13)
		{
			isDone = true;
			cout << game.currentPlayer->GetName() << " wins!" << endl;
		}

		// Change turns
		if (game.currentPlayer == game.player1)
		{
			game.currentPlayer = game.player2;
		}
		else
		{
			game.currentPlayer = game.player1;
		}
	}

}
