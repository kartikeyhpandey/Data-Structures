// RecursionList.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "RecursionList.h"
#include <stack>
#include <stdbool.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool PallindromeByLoop::isPallindrome(string s) {

	if (s.empty())
		return false;

	string revS = "";

	for (int i = s.length() - 1; i >= 0; i--) {
		revS += s[i];
	}
	if (revS.compare(s) == 0)
		return true;
	else
		return false;

}

bool PallindromeByRecursion::isPallindrome(int start, int end, string s) {
	if (s.empty())
		return false;
	if (start >= end)
		return true;
	if (s[start] != s[end])
		return false;
	return isPallindrome(++start, --end, s);
}

bool PallindromeByStack::isPallindrome(string s) {

	int pos = 0;
	string revS = "";
	if (s.length() == 1) { return true; }
	if (s.length() == 0) { return false; }

	while (pos < s.length()) {
		stack.push(s[pos]);
		pos++;
	}
	while (!stack.empty()) {
		revS = revS + stack.top();
		stack.pop();
	}

	if (revS.compare(s) == 0)
		return true;
	else
		return false;

}

void ChessBoard::PrintBoard()
{
	// Initialize board
	std::vector<std::vector<string>> board;

	cout << "  ";
	for (unsigned int i = 0; i < m_size; i++)
	{
		cout << ' ' << i << ' ';

		vector<string> row;
		for (unsigned j = 0; j < m_size; j++)
		{
			row.push_back("[ ]");
		}
		board.push_back(row);
	}

	cout << endl;

	// Add Queens to board
	for (auto&& i : m_moves)
	{
		board[i.x][i.y] = "[*]";
	}

	// Print board
	for (unsigned int i = 0; i < m_size; i++)
	{
		cout << i << " ";
		for (unsigned j = 0; j < m_size; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << endl;
	}
}

bool ChessBoard::CheckQueenConflicts(ChessBoard::position pos)
{
	// Iterate through all current queen placements
	for (auto&& i : m_moves)
	{
		// Check for other queens in row
		if (pos.x == i.x)
		{
			return true;
		}
		// Check for other queens in col
		if (pos.y == i.y)
		{
			return true;
		}
		// Check for other queens in diagonal
		if (abs(pos.x - i.x) == abs(pos.y - i.y))
		{
			return true;
		}
	}

	// Otherwise, there are no conflicts
	return false;
}

void ChessBoard::Solve()
{
	// Set inital position
	position pos = { 0, 0 };

	// While the board is not solved, continue
	while (m_filled != m_size)
	{
		// If the move is valid, add it to the stack
		if (!CheckQueenConflicts(pos))
		{
			m_moves.push_back(pos);
			m_filled += 1;

			// Try adding to the next row
			pos.x += 1;
			pos.y = 0;
		}
		// If there is a conflict and room to the right
		else if (pos.y < m_size - 1)
		{
			pos.y += 1;
		}
		// If there is a conflict but no room to the right
		else if (pos.y == m_size - 1)
		{
			// While the queen cannot be shifted right
			while (m_moves.back().y == m_size - 1)
			{
				// Remove the queen
				m_moves.pop_back();
				m_filled -= 1;
			}

			// Shift the last queen that can be shifted right
			pos = m_moves.back();
			pos.y += 1;
			m_moves.pop_back();
			m_filled -= 1;
		}
	}
}

extern std::string CallSimpleExceptionMethod(int i)
{
	std::string retVal = "I did not get an Exception";

	MyFakeClass* resourceThatNeedsToBeCleanedup = new MyFakeClass();

	try {
		SimpleExceptionMethod(i);
	}
	catch (MyException1& e)
	{
		delete resourceThatNeedsToBeCleanedup;
		return e.what();
	}
	catch (MyException2& e)
	{
		delete resourceThatNeedsToBeCleanedup;
		return e.what();
	}
	catch (MyException3& e)
	{
		delete resourceThatNeedsToBeCleanedup;
		return e.what();
	}


	return retVal;
}


extern void SimpleExceptionMethod(int i)
{
	int retVal = 0;

	if (i == 1)
	{
		throw MyException1();
	}
	else if (i == 2)
	{
		throw MyException2();

	}
	else if (i == 3)
	{
		throw MyException3();
	}
	else
	{
		retVal = 20;
	}

}



char const* MyBaseException::what() const throw() {
	return "MyBaseException";
}
char const* MyException1::what() const throw() {
	return "I got Exception 1";
}
char const* MyException2::what() const throw() {
	return "I got Exception 2";
}
char const* MyException3::what() const throw() {
	return "I got Exception 3";
}