// GraphDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "GraphDLL.h"

GRAPHDLL_API Graphs::Graphs(vector<vector<int>> vert)
{
	arr = new GraphNode[vert.size()];
	for (int k = 0; k < vert.size(); k++) {
		arr[k] = GraphNode(k, vert.size());
	}
	for (int i = 0; i < vert.size(); i++) {
		for (int j = 0; j < vert[0].size(); j++) {
			if (vert[i][j] == 1) {
				addEdge(i, j);
			}
		}
	}
	numVert = vert.size();
}

GRAPHDLL_API Graphs::Graphs(int num)
{
	arr = new GraphNode[num];
	for (int k = 0; k < num; k++)
		arr[k] = GraphNode(k, num);
	numVert = num;
}

GRAPHDLL_API Graphs::~Graphs()
{
	//delete arr;
	/*for (int i = 0; i < numVert; i++)
	{
		delete &arr[i];
	}*/

	//delete []arr;
}

GRAPHDLL_API void Graphs::addEdge(int i, int j) {
	arr[i].out[j] = true;
	arr[j].in[i] = true;
}

GRAPHDLL_API void Graphs::removeEdge(int i, int j) {
	arr[i].out[j] = false;
	arr[j].in[i] = false;
}


GRAPHDLL_API bool Graphs::hasEdge(int i, int j) {
	if (arr[i].out[j] == true && arr[j].in[i] == true)
		return true;
	return false;
}

GRAPHDLL_API vector <int> Graphs::outEdge(int i) {
	vector <int> l;
	for (int k = 0; k < numVert; k++) {
		if (arr[i].out[k] == true) l.push_back(k);
	}
	return l;
}

GRAPHDLL_API vector <int> Graphs::inEdge(int i) {
	vector <int> l;
	for (int k = 0; k < numVert; k++) {
		if (arr[i].in[k] == true) l.push_back(k);
	}
	return l;
}

GRAPHDLL_API string Graphs::print() {
	string str;
	vector<int> outMem;
	for (int i = 0; i < numVert; i++) {
		outMem = this->outEdge(i);
		if (outMem.size() > 0) {
			vector<int>::iterator it;
			str += "Adjacency list of vertex " + to_string(i) + ":\nhead";
			for (it = outMem.begin(); it != outMem.end(); ++it) {
				str += " -> " + to_string(*it);
			}
			str += "\n";
		}
		else {
			str += "Adjacency list of vertex " + to_string(i) + ":\nhead";
			str += " -> null\n";
		}
		continue;
	}
	return str;
}

GRAPHDLL_API GraphNode::GraphNode()
{
}

GRAPHDLL_API GraphNode::~GraphNode()
{
	delete in;
	delete out;
}

GRAPHDLL_API GraphNode::GraphNode(int inVal, int total)
{
	value = inVal;
	in = new bool[total];
	out = new bool[total];
}

GRAPHDLL_API int Graphs::getVertices() 
{
	return numVert;
}
