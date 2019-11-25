#include "../GraphDLL/GraphDLL.h"
#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

int main(int argc, char* args[])
{
	cout << "Welcome to the Graphs Lab\n";
	cout << "Importing data from moves.txt\n";
	ifstream myfile("moves.txt");

	int nodes = 5 , choice = 0;
	bool receivedEndToken = false;
	vector<vector<int>> output;

	string input;
	vector<vector<int>> E;
	
while (input != "-1")
	{
		vector<int> temp;
		getline(myfile, input);
		if (input[0] == '-') break;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] != ' ') {
				temp.push_back(input[i] - 48);
			}
		}
		E.push_back(temp);
	}
	//nodes = output.size();
	Graphs g(E);
	//Graphs g(5);
	while (!receivedEndToken) {
		choice = 0;
		int start;
		int end;
		int point;
		while (choice != 7) {
			cout << "What would you like to do?" << endl;
			cout << "Press 1 to add an edge to graph.\n" <<
				"Press 2 remove an edge from graph.\n" <<
				"Press 3 Find an edge in the graph.\n" <<
				"Press 4 Find the out edges of a vertices.\n" <<
				"Press 5 Find the in edges of a vertices.\n" <<
				"Press 6 To print out Adjacency List.\n" <<
				"Press 7 to quit.\n";
			cin >> choice;
			switch (choice) {
			case 1:	{	// add edge
				cout << "What node would you like to start from? (from 0 to " <<
					to_string(nodes - 1) << ")?\n";
				cin >> start;
				cout << "What node would you like to end at? (from 0 to " <<
					to_string(nodes - 1) << ")?\n";
				cin >> end;
				g.addEdge(start, end);
				cout << "Edge(" << to_string(start) << "," << to_string(end) << ") added.\n";
				g.print();	// to test if it's working - remove later
				receivedEndToken = false;
				break;
			}
			case 2: {	//remove edge
				cout << "What node are you staring from (0 to " << to_string(nodes - 1) << ")?\n";
				cin >> start;
				cout << "What node are you ending at (0 to " << to_string(nodes - 1) << ")?\n";
				cin >> end;
				g.removeEdge(start, end);
				cout << "Edge(" << to_string(start) << "," << to_string(end) << ") removed.\n";
				receivedEndToken = false;
				break;
			}
			case 3: {	//find edge
				cout << "What node are you staring from (0 to " << to_string(nodes - 1) << ")?\n";
				cin >> start;
				cout << "What node are you ending at (0 to " << to_string(nodes - 1) << ")?\n";
				cin >> end;
				if (g.hasEdge(start, end)) 
					cout << "Edge(" << to_string(start) << "," << to_string(end) << ") exists.\n";
				else 
					cout << "Edge(" << to_string(start) << "," << to_string(end) << ") doesn't exists.\n";
				receivedEndToken = true;
				break;
			}
			case 4: {	//outEdges
				cout << "What vertex would you like to see the out edges of? (from 0 to " <<
					to_string(nodes - 1) << ")?\n";
				cin >> point;
				vector<int> outs = g.outEdge(point);
				cout << "Edges of " << to_string(point) << ": {";
				for (int i=0; i<outs.size(); ++i){
          	if(i==(outs.size()-1))
              cout<<outs[i];
            else
              cout << outs[i]<< ",";
        }
				
				cout << "}\n";
				receivedEndToken = false;
				break;
			}
			case 5: {	//inEdges
				cout << "What vertex would you like to see the out edges of? (from 0 to " <<
					to_string(nodes - 1) << ")?\n";
				cin >> point;
				vector<int> ins = g.inEdge(point);
				cout << "Edges of " << to_string(point) << ": {";
				for (int i=0; i<ins.size(); ++i){
          			if(i==(ins.size()-1))
						cout<<ins[i];
					else
						cout << ins[i]<< ",";
        }		cout << "}\n";
				receivedEndToken = false;
				break;
			}
			case 6: {	//print list
				//todo
				cout << "Printing your list:" << endl;
				cout << g.print() << endl;
				receivedEndToken = false;
				break;
			}
			case 7:{	//quit
				receivedEndToken = true;
				break;
			}
			}

		}
	}
	cout << "Thanks for running our program.\n";
	return 0;
	
}
