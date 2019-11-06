#ifdef PQUEUEDLL_EXPORTS
#define PQUEUEDLL_API __declspec(dllexport)
#else
#define PQUEUEDLL_API __declspec(dllimport)
#endif


using namespace std;
#include <string>
#include <vector>


class PQUEUEDLL_API PQueue {
public:
	PQueue();
	~PQueue();
	int remove(); //takes off first value
	void insert(int x); //adds value x
	int find(int x); //returns irst index of value x, -1 if not found
	string print(); //seperated by spaces after every value
	int size(); //returns size of queue
	void sort(); //sorts queue
private:
	vector<int> vec; //sorted S->L
};