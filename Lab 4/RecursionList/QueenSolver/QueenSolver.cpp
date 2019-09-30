// QueenSolver.cpp : Defines the entry point for the console application.
//

#include "..\RecursionList\RecursionList.h"
#include <iostream>
#include <string>


int main()
{
	// Create 8x8 chessboard
	ChessBoard chessBoard(8);

	// Solve the Queen's Problem
	chessBoard.Solve();

	// Print solution
	chessBoard.PrintBoard();
}

