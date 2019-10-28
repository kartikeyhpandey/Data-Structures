#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../BSTDLL/BSTDLL.h"

namespace BSTUnitTests
{
	TEST_CLASS(BSTUnitTests)
	{
	public:
		
		TEST_METHOD(TestTree1)
		{
			BST n;
			vector<string> tree;

			tree.push_back("Galaxy Quest");
			tree.push_back("Space Balls");
			tree.push_back("Star Trek");
			tree.push_back("Star Wars");

			n.Insert("Star Wars");
			n.Insert("Star Trek");
			n.Insert("Space Balls");
			n.Insert("Galaxy Quest");

			vector<string> test = n.GetAllAscending();

			for (unsigned int i = 0; i < tree.size(); i++)
			{
				Assert::AreEqual(tree[i], test[i]);
			}

			test = n.GetAllDescending();

			for (unsigned int i = 0; i < tree.size(); i++)
			{
				Assert::AreEqual(tree[i], test[test.size() - 1 - i]);
			}
			
		}

		TEST_METHOD(TestTree2)
		{
			BST n;
			vector<string> tree;

			tree.push_back("Cars");
			tree.push_back("Monsters Inc");
			tree.push_back("The Incredibles");
			tree.push_back("Wall-E");

			n.Insert("Cars");
			n.Insert("Monsters Inc");
			n.Insert("The Incredibles");
			n.Insert("Wall-E");

			vector<string> test = n.GetAllAscending();

			for (unsigned int i = 0; i < tree.size(); i++)
			{
				Assert::AreEqual(tree[i], test[i]);
			}

			test = n.GetAllDescending();

			for (unsigned int i = 0; i < tree.size(); i++)
			{
				Assert::AreEqual(tree[i], test[test.size() - 1 - i]);
			}
		}

		TEST_METHOD(TestTree3)
		{
			BST n;
			vector<string> tree;

			tree.push_back("A Nightmare On Elm Street");
			tree.push_back("Beetlejuice");
			tree.push_back("Halloween");
			tree.push_back("Hocus Pocus");

			n.Insert("Halloween");
			n.Insert("A Nightmare On Elm Street");
			n.Insert("Hocus Pocus");
			n.Insert("Beetlejuice");

			vector<string> test = n.GetAllAscending();

			for (unsigned int i = 0; i < tree.size(); i++)
			{
				Assert::AreEqual(tree[i], test[i]);
			}

			test = n.GetAllDescending();

			for (unsigned int i = 0; i < tree.size(); i++)
			{
				Assert::AreEqual(tree[i], test[test.size() - 1 - i]);
			}
		}
	};
}
