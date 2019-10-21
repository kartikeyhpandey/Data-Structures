#include<iostream>
using namespace std;


struct node {
	int data;
	node* left;
	node* right;
};

class BST {

	node* Root;

	node* EmptyTree(node* n) {
		if (n == NULL)
			return NULL;
		{
			EmptyTree(n->left);
			EmptyTree(n->right);
			delete n;
		}
		return NULL;
	}

	node* insert(int x, node* n)
	{
		if (n == NULL)
		{
			n = new node;
			n->data = x;
			n->left = n->right = NULL;
		}
		else if (x < n->data)
			n->left = insert(x, n->left);
		else if (x > n->data)
			n->right = insert(x, n->right);
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

	node* remove(int x, node* n) {
		node* temp;
		if (n == NULL)
			return NULL;
		else if (x < n->data)
			n->left = remove(x, n->left);
		else if (x > n->data)
			n->right = remove(x, n->right);
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
		}

		return n;
	}

	void print(node* n) {
		if (n == NULL)
			return;
		print(n->left);
		cout << n->data << " ";
		print(n->right);
	}

	node* find(node* n, int x) {
		if (n == NULL)
			return NULL;
		else if (x < n->data)
			return find(n->left, x);
		else if (x > n->data)
			return find(n->right, x);
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

	void insert(int x) {
		Root = insert(x, Root);
	}

	void remove(int x) {
		Root = remove(x, Root);
	}

	void display() {
		print(Root);
		cout << endl;
	}

	void search(int x) {
		Root = find(Root, x);
	}
};

int main() {
	BST n;
	n.insert(20);
	n.insert(25);
	n.insert(15);
	n.insert(10);
	n.insert(30);
	n.display();
	n.remove(20);
	n.display();
	n.remove(25);
	n.display();
	n.remove(30);
	n.display();
	return 0;
}
