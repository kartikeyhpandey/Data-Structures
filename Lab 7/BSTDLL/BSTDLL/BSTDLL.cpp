// BSTDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "BSTDLL.h"

 using namespace std;

// This is the constructor of a class that has been exported.
BSTDLL_API BST::BST()
{
    m_root = NULL;
	m_counter = 0;
}

BSTDLL_API BST::~BST()
{
	m_root = EmptyTree(m_root);
}

BSTDLL_API int BST::Size()
{
	return m_counter;
}

BSTDLL_API node* BST::EmptyTree(node* n)
{
	if (n == NULL)
			return NULL;
		else {
			EmptyTree(n->left);
			EmptyTree(n->right);
			delete n;
			--m_counter;
		}
		return NULL;
}

BSTDLL_API node* BST::Insert(string x, node* n)
{
		if (n == NULL)
		{
			n = new node;
			n->data = x;
			n->left = n->right = NULL;
			++m_counter;
		}
		else if (x < n->data)
			n->left = Insert(x, n->left);
		else if (x > n->data)
			n->right = Insert(x, n->right);
		return n;
}

BSTDLL_API void BST::GetAllAscending(node* n) {
		if (n == NULL)
			return;
		GetAllAscending(n->left);
		//std::cout << n->data << "\n";
		m_print.push_back(n->data);
		GetAllAscending(n->right);
}

BSTDLL_API void BST::GetAllDescending(node* n) {
		if (n == NULL)
			return;
		GetAllDescending(n->right);
		//std::cout << n->data << "\n";
		m_print.push_back(n->data);
		GetAllDescending(n->left);
}

BSTDLL_API node* BST::FindMin(node* n)
{
		if (n == NULL)
			return NULL;
		else if (n->left == NULL)
			return n;
		else
			return FindMin(n->left);
}

BSTDLL_API node* BST::FindMax(node* n) {
		if (n == NULL)
			return NULL;
		else if (n->right == NULL)
			return n;
		else
			return FindMax(n->right);
}

BSTDLL_API node* BST::Remove(string x, node* n) {
		node* temp;
		if (n == NULL)
		{
			return NULL;
			
		}
		else if (x < n->data)
		{
			n->left = Remove(x, n->left);
		}
		else if (x > n->data)
		{
			n->right = Remove(x, n->right);
		}
		else if (n->left && n->right)
		{
			temp = FindMin(n->right);
			n->data = temp->data;
			n->right = Remove(n->data, n->right);
		}
		else
		{
			temp = n;
			if (n->left == NULL)
				n = n->right;
			else if (n->right == NULL)
				n = n->left;
			delete temp;
			--m_counter;
		}
		return n;
}

BSTDLL_API node* BST::Find(string x, node* n) {
		if (n == NULL)
			return NULL;
		else if (x < n->data)
			return Find(x, n->left);
		else if (x > n->data)
			return Find(x, n->right);
		else
			return n;
}

BSTDLL_API void BST::Insert(std::string s)
{
	m_root = Insert(s, m_root);
}

BSTDLL_API node* BST::Find(std::string s)
{
	m_root = Find(s, m_root);
	return m_root;
}

BSTDLL_API void BST::EmptyTree()
{
	m_root = EmptyTree(m_root);
}

BSTDLL_API node* BST::Remove(std::string s)
{
	m_root = Remove(s, m_root);
	return m_root;
}

BSTDLL_API vector<string>& BST::GetAllAscending()
{
	m_print.clear();
	GetAllAscending(m_root);
	return m_print;
}

BSTDLL_API vector<string>& BST::GetAllDescending()
{
	m_print.clear();
	GetAllDescending(m_root);
	return m_print;
}
