#include <iostream>
#include <string>
using namespace std;

struct node {
	string data;
	node* left;
	node* right;
};

class BST {

	node* Root;
	int counter = 0;

	node* EmptyTree(node* n) {
		if (n == NULL)
			return NULL;
		else {
			EmptyTree(n->left);
			EmptyTree(n->right);
			delete n;
			--counter;
		}
		return NULL;
	}

	node* Insert(string x, node* n)
	{
		if (n == NULL)
		{
			n = new node;
			n->data = x;
			n->left = n->right = NULL;
			++counter;
		}
		else if (x < n->data)
			n->left = Insert(x, n->left);
		else if (x > n->data)
			n->right = Insert(x, n->right);
		return n;
	}

	node* findMin(node* n)
	{
		if (n == NULL)
			return NULL;
		else if (n->left == NULL)
			return n;
		else
			return findMin(n->left);
	}

	node* findMax(node* n) {
		if (n == NULL)
			return NULL;
		else if (n->right == NULL)
			return n;
		else
			return findMax(n->right);
	}

	node* remove(string x, node* n) {
		node* temp;
		if (n == NULL)
		{
			return NULL;
			
		}
		else if (x < n->data)
		{
			n->left = remove(x, n->left);
		}
		else if (x > n->data)
		{
			n->right = remove(x, n->right);
		}
		else if (n->left && n->right)
		{
			temp = findMin(n->right);
			n->data = temp->data;
			n->right = remove(n->data, n->right);
		}
		else
		{
			temp = n;
			if (n->left == NULL)
				n = n->right;
			else if (n->right == NULL)
				n = n->left;
			delete temp;
			--counter;
		}
		return n;
	}

	void GetAllAscending(node* n) {
		if (n == NULL)
			return;
		GetAllAscending(n->left);
		cout << n->data << "\n";
		GetAllAscending(n->right);
	}

	void GetAllDescending(node* n) {
		if (n == NULL)
			return;
		GetAllDescending(n->right);
		cout << n->data << "\n";
		GetAllDescending(n->left);

	}

	node* Find(node* n, string x) {
		if (n == NULL)
			return NULL;
		else if (x < n->data)
			return Find(n->left, x);
		else if (x > n->data)
			return Find(n->right, x);
		else
			return n;
	}


public:
	BST() {
		Root = NULL;
	}

	~BST() {
		Root = EmptyTree(Root);
	}

	int Size()
	{
		return counter;
	}

	void Insert(string x) {
		Root = Insert(x, Root);
	}

	void remove(string x) {
		Root = remove(x, Root);
	}

	void GetAllAscending() {
		GetAllAscending(Root);
		cout << endl;
	}

	void GetAllDescending() {
		GetAllDescending(Root);
		cout << endl;
	}

	void Find(string x) {
		Root = Find(Root, x);
	}

	void EmptyTree() {
		Root = EmptyTree(Root);
	}
};

int main() {
	BST n;
	n.Insert("Star Wars");
	n.Insert("Star Trek");
	n.Insert("Space Balls");
	n.Insert("Galaxy Quest");
	cout << n.Size() << endl;
	n.GetAllAscending();
	n.GetAllDescending();
	n.EmptyTree();

	n.Insert("Cars");
	n.Insert("Monsters Inc");
	n.Insert("The Incredibles");
	n.Insert("Wall-E");
	cout << n.Size() << endl;
	n.GetAllAscending();
	n.GetAllDescending();
	n.EmptyTree();

	n.Insert("Halloween");
	n.Insert("A Nightmare On Elm Street");
	n.Insert("Hocus Pocus");
	n.Insert("Beetlejuice");
	cout << n.Size() << endl;
	n.GetAllAscending();
	n.GetAllDescending();

	return 0;
}