// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the GRAPHDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// GRAPHDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef GRAPHDLL_EXPORTS
#define GRAPHDLL_API __declspec(dllexport)
#else
#define GRAPHDLL_API __declspec(dllimport)
#endif

// This class is exported from the dll

using namespace std;
#include <list>
#include <vector>
#include <string>
#include <algorithm>

class GRAPHDLL_API GraphNode {
public:
	GraphNode();
	GraphNode(int inVal, int total);
	~GraphNode();

	//variables
	int value;
	bool* out;		// contains all points from selected point ; data[x].out = {t, r, f} such that {(x,t),(x,r),(x,f)}; children
	bool* in;		// contains all points INTO selected points; data[x].in  = {t, r, f} such that {(t,x),(r,x),(f,x)}; parents
};


class GRAPHDLL_API Graphs {
public:
	Graphs(vector<vector<int>> vert); //contructor w/ vert amount of Leafs
	Graphs(int num);
	~Graphs(); //deconstructor
	void addEdge(int i, int j); //adds edge i->j
	void removeEdge(int i, int j); //removes edge i->j
	bool hasEdge(int i, int j); //checks if edge exists
	vector <int> outEdge(int i); //points from i
	vector <int> inEdge(int i); //points to i
	string print(); //prints out all graph
	int getVertices(); //Returns the number of verticies of the Graph

private:
	GraphNode* arr;
	int numVert;
};