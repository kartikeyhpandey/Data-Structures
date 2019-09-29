// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

ILinkedList::ILinkedList() : m_count(0)
{

}

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	delete m_next;
}

PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{
	m_count = 0;
	m_head = nullptr;
}
/** Returns true  if list is empty, otherwise true */
bool PointerBasedLinkedList::isEmpty() const
{
	return m_count==0;
}
/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	Node* cur = m_head;
	for (int i = 0; i < m_count - 1; i++) {
		cur = cur->getNext(); //getting the next node
	}

	Node* last = new Node(val);
	if (cur == nullptr)
		m_head = last;
	else
		cur->setNext(last);
	m_count++; // increasing the count of elements
	return true;
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	Node* cur = m_head;
	Node* prv = nullptr;
	while (cur != nullptr) {
		if (cur->getItem() == val) {
			if (prv == nullptr)
				m_head = cur -> getNext();
			else
				prv->setNext(cur->getNext());
			cur->setNext(nullptr);
			delete cur;
			m_count--;
			return true;
		}
		prv = cur;
		cur = cur->getNext();
	} //traversing through the linked list
	return false;
}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	if (m_head != nullptr)
		delete m_head;
	m_head = NULL;
	m_count = 0;
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	clear();
}

std::string PointerBasedLinkedList::toString() const
{
	string str = "";
	Node* cur = m_head;
	while (cur != nullptr) {
		if (cur != m_head)
			str += " ";
		str += to_string(cur->getItem());
		cur = cur->getNext();
	}
	return str;
}

ArrayBasedLinkedList::ArrayBasedLinkedList() : ILinkedList()
{
	m_count = 0;
	for (int i = 0; i < 10; ++i) {
		m_values[i] = 0;
	}
}

bool ArrayBasedLinkedList::isEmpty() const
{
	return m_count==0;	
}
bool ArrayBasedLinkedList::add(int val)
{
	if (m_count < sizeof(m_values)/sizeof(m_values[0])) {
		m_values[m_count] = val;
		m_count++;
		return true;
	}
	return false;
}
bool ArrayBasedLinkedList::remove(int val)
{
		for (int i = 0; i < m_count; i++) {
			if (m_values[i] == val) {
				m_count--;
				for (int j = i; j < m_count; j++)
					m_values[j] = m_values[j + 1];
				return true;
			}
		}
	return false;
}
void ArrayBasedLinkedList::clear()
{
	m_count = 0;
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}

std::string ArrayBasedLinkedList::toString() const
{
	string str = "";
	for (int i = 0; i < m_count; i++) {
		if (i > 0)
			str += " "; //adding a space after a new element
		str += to_string(m_values[i]);
	} //traversing through the array
	return str;
}
