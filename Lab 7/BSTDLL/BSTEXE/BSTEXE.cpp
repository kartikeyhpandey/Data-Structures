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
	std::cout << n.Size() << std::endl;
	tree = n.GetAllAscending();

	for (auto i : tree)
	{
		cout << i << endl;
	}
	cout << endl;

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
	std::cout << n.Size() << std::endl;
	tree = n.GetAllAscending();

	for (auto i : tree)
	{
		cout << i << endl;
	}
	cout << endl;

	tree = n.GetAllDescending();

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
	std::cout << n.Size() << std::endl;
	tree = n.GetAllAscending();

	for (auto i : tree)
	{
		cout << i << endl;
	}
	cout << endl;

	tree = n.GetAllDescending();

	for (auto i : tree)
	{
		cout << i << endl;
	}
	cout << endl;

	return 0;
}
