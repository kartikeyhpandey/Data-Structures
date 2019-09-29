// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "StackQueues.h"
#include <iostream>

ArrayBasedStack::ArrayBasedStack(void) {

}

ArrayBasedStack::~ArrayBasedStack() {

}

bool ArrayBasedStack::push(int val) {
	if (height < 100) {
		arr[height] = val;
		height++;
		return true;
	}
	else {
		throw "Array limits exceeded";
		return false;
	}
}

bool ArrayBasedStack::pop() {
	if (height > 0) {
		height--;
		return arr[height-1];
	}
	else {
		std::cout << "Array limits exceeded";
		return false;
	}
}

int ArrayBasedStack::top() {
	if (height > 0)
		return arr[height - 1];
	else
		throw "Array limits exceeded";
}

bool ArrayBasedStack::isEmpty() const {
	if (height > 0)
		return false;
	else
		return true;
}

int ArrayBasedStack::peek() {
	if (this->isEmpty())
		throw "ADT is emtpy";
	else
		return arr[height - 1];
}

int ArrayBasedStack::length() {
	return height;
}

int ArrayBasedStack::get(int n) {
	return arr[n];
}

void ArrayBasedStack::empty() {
	for (int i = 0; i < height; i++) {
		arr[i] = 0;
	}
	height = 0;
}

ArrayBasedQueue::ArrayBasedQueue(void) {

}

ArrayBasedQueue::~ArrayBasedQueue() {

}

std::string ArrayBasedQueue::peekFront() {
	if (this->isEmpty())
		throw "ADT is emtpy";
	else
		return arr[height - 1];
}

bool ArrayBasedQueue::isEmpty() const {
	return (height == 0);
}

bool ArrayBasedQueue::enQueue(std::string val) {
	if (height < 100) {
		for (int k = height; k > 0; k--)
			arr[k] = arr[k - 1];
		arr[0] = val;
		height++;
		return true;
	}
	else
		return false;
}

bool ArrayBasedQueue::deQueue() {
	if (height > 0) {
		height--;
		return true;
	}
	else
		return false;
}