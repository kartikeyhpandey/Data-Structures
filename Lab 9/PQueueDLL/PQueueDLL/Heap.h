#ifdef PQUEUEDLL_EXPORTS
#define PQUEUEDLL_API __declspec(dllexport)
#else
#define PQUEUEDLL_API __declspec(dllimport)
#endif

#pragma once

#include <string>
#define MAXSIZE 5000

class PQUEUEDLL_API Heap{
private:
	int heap[MAXSIZE];
	int currentSize;
	int height;
	int getParentIndex(int nodeIndex);
	int getLeftIndex(int nodeIndex);
	int getRightIndex(int nodeIndex);
	void maxHeap(int nodeIndex);
public:
	Heap();
	void maxHeap();
	int getCurrentSize();
	int getMaxSize();
	int getHeight();
	void insert(int val);
	bool remove();
	int peek();
	bool isLeaf(int nodeIndex);
	bool isEmpty();
	void clear();
	std::string printHeap();
};
