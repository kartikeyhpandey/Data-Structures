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

			Assert::IsTrue(g.addItem("Kartikey")); //addItem
			Assert::IsTrue(g.addItem("Peter"));
			Assert::IsTrue(g.addItem("Alex"));
			Assert::IsTrue(g.addItem("random"));
			Assert::IsFalse(g.addItem("c++"));

			

			
			/*Node* node = g.getItem("Kartikey");
			string str = node->data;

			Assert::AreEqual(str, string("Kartikey")); //node ==
			
			g.~HashTables();*/

		}
		
		TEST_METHOD(getItem)
		{
			HashTables g = HashTables(4);

			Assert::IsTrue(g.addItem("Kartikey")); //addItem
			Assert::IsTrue(g.addItem("Peter"));
			Assert::IsTrue(g.addItem("Alex"));
			Assert::IsTrue(g.addItem("random"));
			Assert::IsFalse(g.addItem("c++"));

			Assert::IsTrue(g.getItem("Kartikey")!=nullptr); //getItem
			Assert::IsFalse(g.getItem("random")==nullptr);
			Assert::IsTrue(g.getItem("c#")==nullptr);
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

			Assert::IsTrue(g.addItem("Kartikey")); //addItem
			Assert::IsTrue(g.addItem("Peter"));
			Assert::IsTrue(g.addItem("Alex"));
			Assert::IsTrue(g.addItem("Ryan"));
			
			Assert::IsTrue(g.getItem("Kartikey") != nullptr);
			Assert::IsTrue(g.removeItem("Kartikey") == nullptr);
			Assert::IsTrue(g.getItem("Kartikey") == nullptr);

			Assert::IsTrue(g.getItem("Ryan") != nullptr);
			Assert::IsTrue(g.removeItem("Ryan") == nullptr);
			Assert::IsTrue(g.getItem("Ryan") == nullptr);

		}
	};
}
