#include "Heap.h"
#include <math.h>
#define MAXSIZE 5000

PQUEUEDLL_API Heap::Heap()
{
	std::fill_n(heap, MAXSIZE, 0);
	currentSize = 0;
	height = 0;
}

PQUEUEDLL_API int Heap::getCurrentSize()
{
	return currentSize;
}

PQUEUEDLL_API int Heap::getMaxSize()
{
	return MAXSIZE;
}

PQUEUEDLL_API int Heap::getHeight()
{
	return ceil(log2(currentSize + 1)) - 1;
}

PQUEUEDLL_API void Heap::insert(int val)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (heap[i] == 0)
		{
			heap[i] = val;
			currentSize++;
			height = ceil(log2(currentSize +    1)) - 1;
			return;
		}
	}
}

PQUEUEDLL_API bool Heap::remove()
{
	if (heap[0] == 0) return false;
	for (int i = 0; i < MAXSIZE - 1; i++)
	{
		heap[i] = heap[i + 1];
	}
	currentSize--;
	return true;
}

PQUEUEDLL_API int Heap::peek()
{
	return heap[0];
}

PQUEUEDLL_API int Heap::getParentIndex(int nodeIndex)
{
	return (nodeIndex - 1) / 2;
}

PQUEUEDLL_API int Heap::getLeftIndex(int nodeIndex)
{
	return (nodeIndex * 2) + 1;
}

PQUEUEDLL_API int Heap::getRightIndex(int nodeIndex)
{
	return (nodeIndex * 2) + 2;
}

PQUEUEDLL_API void Heap::maxHeap()
{
	maxHeap((currentSize / 2) - 1);
}

PQUEUEDLL_API void Heap::maxHeap(int start)
{
	for (int i = start; i >= 0; i--)
	{
		if (heap[i] < heap[getRightIndex(i)] && heap[getRightIndex(i)] >= heap[getLeftIndex(i)])
		{
			int temp = heap[i];
			heap[i] = heap[getRightIndex(i)];
			heap[getRightIndex(i)] = temp;
			if (!isLeaf(getRightIndex(i)))
			{
				maxHeap(heap[getRightIndex(i)]);
				maxHeap(heap[getLeftIndex(i)]);
			}
		}
		else if (heap[i] < heap[getLeftIndex(i)] && heap[getLeftIndex(i)] >= heap[getRightIndex(i)])
		{
			int temp = heap[i];
			heap[i] = heap[getLeftIndex(i)];
			heap[getLeftIndex(i)] = temp;
			if (!isLeaf(getRightIndex(i)))
			{
				maxHeap(heap[getRightIndex(i)]);
				maxHeap(heap[getLeftIndex(i)]);
			}
		}
	}
}

PQUEUEDLL_API bool Heap::isLeaf(int nodeIndex)
{
	if (nodeIndex >= currentSize - 2)
		return true;
	return false;
}

PQUEUEDLL_API bool Heap::isEmpty()
{
	if (currentSize == 0) return true;
	return false;
}

PQUEUEDLL_API void Heap::clear()
{
	int i = 0;
	while (heap[i] != 0)
	{
		this->remove();
	}
}

PQUEUEDLL_API std::string Heap::printHeap()
{
	std::string outStr;
	for (int i = 0; i < getCurrentSize(); i++)
	{
		outStr += std::to_string(heap[i]);
		outStr += " ";
	}
	return outStr;
}

