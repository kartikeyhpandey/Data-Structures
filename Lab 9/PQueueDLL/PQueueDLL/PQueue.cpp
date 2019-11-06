#include "PQueue.h"
#include <string>
#include <vector>

using namespace std;

PQUEUEDLL_API PQueue::PQueue() {}
PQUEUEDLL_API PQueue::~PQueue() {}
PQUEUEDLL_API int PQueue::remove() { //takes off first value
	int temp = vec.back();
	vec.pop_back();
	return temp;
}
PQUEUEDLL_API void PQueue::insert(int x) { //adds value x
	vec.push_back(x);
	this->sort();
}
PQUEUEDLL_API int PQueue::find(int x) { //returns first index of value x, -1 if not found
	for (int k = 0; k < this->size(); k++) {
		if (vec[k] == x)
			return k;
	}
	return -1;
}
PQUEUEDLL_API string PQueue::print() { //seperated by spaces after every value
	string str = "";
	for (int k = 0; k < this->size(); k++) {
		str += to_string(vec[k]) + " ";
	}
	return str;
}
PQUEUEDLL_API int PQueue::size() { //returns size of queue
	return vec.size();
}
PQUEUEDLL_API void PQueue::sort() { //sorts queue
	bool sorted = false;
	int marker = this->size(); //keeps track of "end" of array
	int next; //holds temp int for switch
	while (!sorted) { //runs thru entire sequence until all elements are in order
		sorted = true;
		for (int k = 0; k < marker - 1; k++) { //goes thru unprocessed numbers
			if (vec[k + 1] < vec[k]) { //check for swap
				next = vec[k+1];
				vec[k+1] = vec[k];
				vec[k] = next;
				sorted = false;
			}
		}
		marker--;
	}
}