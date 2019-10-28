// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the BSTDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// BSTDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BSTDLL_EXPORTS
#define BSTDLL_API __declspec(dllexport)
#else
#define BSTDLL_API __declspec(dllimport)
#endif

#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct node
{
	std::string data;
	node* left = nullptr;
	node* right = nullptr;
};

// This class is exported from the dll
class BSTDLL_API BST {
public:
	BST();
	~BST();
	
	void Insert(std::string s);
	node* Find(std::string val);
	int Size();
	void EmptyTree();
	node* Remove(std::string val);
	vector<string>& GetAllAscending();
	vector<string>& GetAllDescending();

private:
	node* EmptyTree(node* n);
	node* Insert(std::string s, node* n);
	node* FindMin(node* n);
	node* FindMax(node* n);
	node* Remove(std::string s, node* n);
	node* Find(std::string s, node* n);
	void GetAllAscending(node* n);
	void GetAllDescending(node* n);

	node* m_root;
	int m_counter;
	vector<string> m_print;
};
