// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the HASHDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// HASHDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef HASHDLL_EXPORTS
#define HASHDLL_API __declspec(dllexport)
#else
#define HASHDLL_API __declspec(dllimport)
#endif

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class HASHDLL_API Node {
public:
//functions
	Node() {}
	~Node() {}
	Node(int newData, int newKey) {
		data = newData;
		key = newKey;
	}
	bool operator==(Node& a) {
		return a.data == this->data;
	}

//variables
	int data;
	int key;
};


class HASHDLL_API HashTables {
public:
	HashTables();
	~HashTables();
	HashTables(int size);
	bool addItem(int data); //true if successful
	Node* removeItem(int data);
	Node* getItem(int data);
	int getLength();
private:
	int Hash(int data);
	int maxSize = 100;
	int count = 0;
	//Node **list;
	vector<Node*> list;
	Node *node;
};