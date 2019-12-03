#include "pch.h"
#include "CppUnitTest.h"
#include "../HashDLL/HashDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashUnitTests
{
	TEST_CLASS(HashUnitTests)
	{
	public:
		TEST_METHOD(addItem) {
			//addItem, getLength, getItem, node ==
			HashTables g = HashTables(4);

			Assert::IsTrue(g.addItem(69)); //addItem
			Assert::IsTrue(g.addItem(17));
			Assert::IsTrue(g.addItem(420));
			Assert::IsTrue(g.addItem(123));
			Assert::IsFalse(g.addItem(17));

			

			
			/*Node* node = g.getItem("Kartikey");
			string str = node->data;

			Assert::AreEqual(str, string("Kartikey")); //node ==
			
			g.~HashTables();*/

		}
		
		TEST_METHOD(getItem)
		{
			HashTables g = HashTables(4);

			Assert::IsTrue(g.addItem(69)); //addItem
			Assert::IsTrue(g.addItem(17));
			Assert::IsTrue(g.addItem(420));
			Assert::IsTrue(g.addItem(123));
			Assert::IsFalse(g.addItem(17));

			Assert::IsTrue(g.getItem(69)!=NULL); //getItem
			Assert::IsFalse(g.getItem(123)==NULL);
			Assert::IsTrue(g.getItem(42)==NULL);
		}
		
		TEST_METHOD(getLength)
		{
			HashTables g = HashTables(4);
			
			Assert::AreEqual(int(4), g.getLength()); //getLength
			Assert::AreNotEqual(int(5), g.getLength());

		}

		TEST_METHOD(removeItem)
		{

			HashTables g = HashTables(4);

			Assert::IsTrue(g.addItem(123)); //addItem
			Assert::IsTrue(g.addItem(17));
			Assert::IsTrue(g.addItem(77));
			Assert::IsTrue(g.addItem(456));
			
			Assert::IsTrue(g.getItem(123) != NULL);
			Assert::IsTrue(g.removeItem(123) == NULL);
			Assert::IsTrue(g.getItem(123) == NULL);

			Assert::IsTrue(g.getItem(17) != NULL);
			Assert::IsTrue(g.removeItem(17) == NULL);
			Assert::IsTrue(g.getItem(17) == NULL);

		}
	};
}
