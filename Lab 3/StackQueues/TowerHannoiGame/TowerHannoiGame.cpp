
#include "..\StackQueues\StackQueues.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TowersOfHannoiGame
{
public:
	TowersOfHannoiGame() : m_GameEnded(false)
	{
		stk[0] = new ArrayBasedStack();
		stk[1] = new ArrayBasedStack();
		stk[2] = new ArrayBasedStack();
		que = new ArrayBasedQueue();
		//build disk, val is width
		stk[0]->push(4);
		stk[0]->push(3);
		stk[0]->push(2);
		stk[0]->push(1);
	}

	bool IsGameEnded() { return m_GameEnded; }

	void PrintTowers()
	{
		std::string str[5];
		str[0] = "             ";
		str[1] = "     |_|     "; //smallest disk
		str[2] = "    |_|_|    ";
		str[3] = "   |_|_|_|   ";
		str[4] = "  |_|_|_|_|  "; //largest disk
		std::string base = "  *********  "; //base

		for (int g = 3; g >= 0; g--) {
			for (int k = 0; k < 3; k++) {
				if (stk[k]->length() > g) {
					int val = stk[k]->get(g);
					cout << str[val];
				}
				else {
					cout << str[0];
				}
			}
			cout << "\n";
		}
		cout << base + base + base;
		cout << "\n";
	}

	bool move(int disk, int from, int to) {
		//error checking
		from--;
		to--;
		if (from < 0 || from > 2)
			return false;
		if (to < 0 || to > 2)
			return false;
		if (disk < 1 || disk > 4)
			return false;
		if (stk[from]->length() < 0)
			return false;
		if (stk[from]->top() != disk)
			return false;
		if ((stk[to]->length() > 0) && (stk[to]->top() < disk))
			return false;

		//do stuff
		stk[from]->pop();
		stk[to]->push(disk);
		return true;
	}

private:
	bool m_GameEnded;
	ArrayBasedStack* stk[3];
	ArrayBasedQueue* que;

};

int main()
{

	cout << "Enter in moves to make for Towers  of  Hannoi" << endl;
	cout << "Progam will exit once towers have  been successfully moved of" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to>   NOTE no spaces!!!!" << endl;

	TowersOfHannoiGame game;

	bool receivedEndToken = false;

	while (!receivedEndToken || game.IsGameEnded())
	{
		std::string inputLine;
		game.PrintTowers();
		cout << "Enter Move " << endl;
		getline(cin, inputLine);
		if (inputLine == "-1")
		{
			receivedEndToken = true;
		}
		else
		{
			std::vector<std::string> output;
			std::string::size_type prev_pos = 0, pos = 0;
			// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
			// tokenizing a string
			while ((pos = inputLine.find(",", pos)) != std::string::npos)
			{
				std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
				output.push_back(substring);
				prev_pos = ++pos;
			}
			//Need to get last token
			output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

			if (output.size() != 3)
			{
				receivedEndToken = true;
				cout << "Invalid input recieved = " + inputLine << endl;
			}
			else
			{
				std::string disk = output[0];
				std::string from = output[1];
				std::string to = output[2];

				if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				int diskId = atoi(disk.c_str());
				int fromId = atoi(from.c_str());
				int toId = atoi(to.c_str());
				//if any number is zero we didn't have a integer
				if (diskId == 0 || fromId == 0 || toId == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}
				//my stuff
				if (game.move(diskId, fromId, toId)) {
					cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;
				}
				else {
					cout << "Invalid move\n";
				}
				//my stuff



			}
		}



	}

	return 0;
}

