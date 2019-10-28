#include <iostream>

#include "../BSTDLL/BSTDLL.h"

int main()
{
	BST n;
	vector<string> tree;

	n.Insert("Star Wars");
	n.Insert("Star Trek");
	n.Insert("Space Balls");
	n.Insert("Galaxy Quest");
	std::cout << "Tree Size: " << n.Size() << std::endl;
	tree = n.GetAllAscending();

	cout << "Tree 1 Ascending" << endl;
	cout << "----------------" << endl;

	for (auto i : tree)
	{
		cout << i << endl;
	}
	cout << endl;

	cout << "Tree 1 Descending" << endl;
	cout << "----------------" << endl;

	tree = n.GetAllDescending();

	for (auto i : tree)
	{
		cout << i << endl;
	}
	cout << endl;

	n.EmptyTree();

	n.Insert("Cars");
	n.Insert("Monsters Inc");
	n.Insert("The Incredibles");
	n.Insert("Wall-E");
	std::cout << "Tree Size: " << n.Size() << std::endl;
	tree = n.GetAllAscending();

	cout << "Tree 2 Ascending" << endl;
	cout << "----------------" << endl;

	for (auto i : tree)
	{
		cout << i << endl;
	}
	cout << endl;

	tree = n.GetAllDescending();

	cout << "Tree 2 Ascending" << endl;
	cout << "----------------" << endl;

	for (auto i : tree)
	{
		cout << i << endl;
	}
	cout << endl;
	n.EmptyTree();

	n.Insert("Halloween");
	n.Insert("A Nightmare On Elm Street");
	n.Insert("Hocus Pocus");
	n.Insert("Beetlejuice");
	std::cout << "Tree Size: " << n.Size() << std::endl;
	tree = n.GetAllAscending();

	cout << "Tree 3 Ascending" << endl;
	cout << "----------------" << endl;

	for (auto i : tree)
	{
		cout << i << endl;
	}
	cout << endl;

	tree = n.GetAllDescending();

	cout << "Tree 3 Descending" << endl;
	cout << "----------------" << endl;

	for (auto i : tree)
	{
		cout << i << endl;
	}
	cout << endl;

	return 0;
}
