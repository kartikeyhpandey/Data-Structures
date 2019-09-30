// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the RECURSIONLIST_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// RECURSIONLIST_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef RECURSIONLIST_EXPORTS
#define RECURSIONLIST_API __declspec(dllexport)
#else
#define RECURSIONLIST_API __declspec(dllimport)
#endif
#include <vector>
#include <string>
#include <stack>
#include <list>
#include <iostream>

using namespace std;

class RECURSIONLIST_API IPallindromeComputer
{
public:
	IPallindromeComputer() {};
	virtual bool isPallindrome(string wordToComputer) = 0;
};

class RECURSIONLIST_API PallindromeByLoop : public IPallindromeComputer
{
public:
	PallindromeByLoop() {};
	bool isPallindrome(string s);
};

class RECURSIONLIST_API PallindromeByRecursion 
{
public:
	PallindromeByRecursion() {};
	bool isPallindrome(int start, int end, string s);
};
class RECURSIONLIST_API PallindromeByStack : public IPallindromeComputer
{
public:
	PallindromeByStack() {};
	//TODO add in missing method to allow this to compile
	
	bool isPallindrome(string s) override;

private:
	std::stack <char> stack;
};

class RECURSIONLIST_API MyFakeClass
{
public:
	MyFakeClass() {}
	~MyFakeClass() { std::cout << "Destructor for MyFakeClass was called" << std::endl; }

};

class RECURSIONLIST_API MyBaseException : public std::exception
{
public:
	//	//TODO 
	virtual char const* what() const throw();
};

class RECURSIONLIST_API MyException1 : MyBaseException
{
public:
	//	//TODO 
	virtual char const* what() const throw();
};


class RECURSIONLIST_API MyException2 : MyBaseException
{
public:
	//	//TODO 
	virtual char const* what() const throw();
};

class RECURSIONLIST_API MyException3 : MyBaseException
{
public:
	//	//TODO 
	virtual char const* what() const throw();
};

extern RECURSIONLIST_API std::string CallSimpleExceptionMethod(int i);
extern RECURSIONLIST_API void SimpleExceptionMethod(int i);


class RECURSIONLIST_API ChessBoard {
public:
	// Custom data type for board positions
	struct position
	{
		int x;
		int y;
	};

	// Board constructor
	ChessBoard(int size)
	{
		m_size = size;
	}

	// Solve the Queen's Problem
	void Solve();

	// Print the board
	void PrintBoard();

private:
	bool CheckQueenConflicts(position pos);

	int m_size;
	int m_filled = 0;
	std::list<position> m_moves;
};
