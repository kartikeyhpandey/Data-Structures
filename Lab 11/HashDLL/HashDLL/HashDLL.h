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

using namespace std;

class HASHDLL_API Node {
public:
//functions
	Node() {}
	Node(string newData, int newKey) {
		data = newData;
		key = newKey;
	}
	bool operator==(Node& a) {
		return a.data == this->data;
	}

//variables
	string data;
	int key;
};


class HASHDLL_API HashTables {
public:
	HashTables();
	~HashTables();
	HashTables(int size);
	bool addItem(string data); //true if successful
	Node* removeItem(string data);
	Node* getItem(string data);
	int getLength();
private:
	int Hash(string data);
	int maxSize = 100;
	int count = 0;
	Node **list;
	Node *node;
};