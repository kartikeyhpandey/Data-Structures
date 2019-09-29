#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\..\LinkedList\LinkedList\LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(ArrayBasedLinkedListTestEmpy)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());

			Assert::AreEqual(std::string(""), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(ArrayBasedLinkedListTest1Add)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}
		TEST_METHOD(ArrayBasedLinkedListTest2Add)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 2"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(ArrayBasedLinkedListTest3Add)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 2 3"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(ArrayBasedLinkedListTest11Add)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));
			Assert::IsTrue(linkedList.add(4));
			Assert::IsTrue(linkedList.add(5));
			Assert::IsTrue(linkedList.add(6));
			Assert::IsTrue(linkedList.add(7));
			Assert::IsTrue(linkedList.add(8));
			Assert::IsTrue(linkedList.add(9));
			Assert::IsTrue(linkedList.add(10));
			Assert::IsFalse(linkedList.add(11));//Capacity is 11 so won't add

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 2 3 4 5 6 7 8 9 10"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(ArrayBasedLinkedListTestRemoveNonExistant)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));

			Assert::IsFalse(linkedList.remove(4));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 2 3"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(ArrayBasedLinkedListTestBeginingRemove)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));

			Assert::IsTrue(linkedList.remove(1));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("2 3"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(ArrayBasedLinkedListTestMiddleRemove)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));

			Assert::IsTrue(linkedList.remove(2));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 3"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(ArrayBasedLinkedListTestEndRemove)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));

			Assert::IsTrue(linkedList.remove(3));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 2"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(ArrayBasedLinkedListTestMultipleRemove)
		{
			ArrayBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));
			Assert::IsTrue(linkedList.add(4));
			Assert::IsTrue(linkedList.add(5));
			Assert::IsTrue(linkedList.add(6));
			Assert::IsTrue(linkedList.add(7));
			Assert::IsTrue(linkedList.add(8));
			Assert::IsTrue(linkedList.add(9));
			Assert::IsTrue(linkedList.add(10));
			Assert::IsFalse(linkedList.add(11));

			Assert::IsTrue(linkedList.remove(2));
			Assert::IsTrue(linkedList.remove(4));
			Assert::IsTrue(linkedList.remove(6));
			Assert::IsTrue(linkedList.remove(8));

			Assert::IsFalse(linkedList.remove(2));
			Assert::IsFalse(linkedList.remove(4));
			Assert::IsFalse(linkedList.remove(6));
			Assert::IsFalse(linkedList.remove(8));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 3 5 7 9 10"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(PointerBasedLinkedListTestEmpy)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());

			Assert::AreEqual(std::string(""), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(PointerBasedLinkedListTest1Add)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(PointerBasedLinkedListTest2Add)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 2"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(PointerBasedLinkedListTest3Add)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 2 3"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(PointerBasedLinkedListTest1)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));
			Assert::IsTrue(linkedList.add(4));
			Assert::IsTrue(linkedList.add(5));
			Assert::IsTrue(linkedList.add(6));
			Assert::IsTrue(linkedList.add(7));
			Assert::IsTrue(linkedList.add(8));
			Assert::IsTrue(linkedList.add(9));
			Assert::IsTrue(linkedList.add(10));
			Assert::IsTrue(linkedList.add(11));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 2 3 4 5 6 7 8 9 10 11"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(PointerBasedLinkedListTestRemoveNonExistant)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));

			Assert::IsFalse(linkedList.remove(4));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 2 3"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(PointerBasedLinkedListTestBeginningRemove)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));

			Assert::IsTrue(linkedList.remove(1));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("2 3"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(PointerBasedLinkedListTestMiddleRemove)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));

			Assert::IsTrue(linkedList.remove(2));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 3"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

		TEST_METHOD(PointerBasedLinkedListTestEndRemove)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));

			Assert::IsTrue(linkedList.remove(3));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 2"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}



		TEST_METHOD(PointerBasedLinkedListTestMultipleRemove)
		{
			PointerBasedLinkedList linkedList;
			Assert::IsTrue(linkedList.isEmpty());
			Assert::IsTrue(linkedList.add(1));
			Assert::IsTrue(linkedList.add(2));
			Assert::IsTrue(linkedList.add(3));
			Assert::IsTrue(linkedList.add(4));
			Assert::IsTrue(linkedList.add(5));
			Assert::IsTrue(linkedList.add(6));
			Assert::IsTrue(linkedList.add(7));
			Assert::IsTrue(linkedList.add(8));
			Assert::IsTrue(linkedList.add(9));
			Assert::IsTrue(linkedList.add(10));
			Assert::IsTrue(linkedList.add(11));

			Assert::IsTrue(linkedList.remove(2));
			Assert::IsTrue(linkedList.remove(4));
			Assert::IsTrue(linkedList.remove(6));
			Assert::IsTrue(linkedList.remove(8));

			Assert::IsFalse(linkedList.remove(2));
			Assert::IsFalse(linkedList.remove(4));
			Assert::IsFalse(linkedList.remove(6));
			Assert::IsFalse(linkedList.remove(8));

			Assert::IsFalse(linkedList.isEmpty());

			Assert::AreEqual(std::string("1 3 5 7 9 10 11"), linkedList.toString());

			linkedList.clear();
			Assert::IsTrue(linkedList.isEmpty());
		}

	};
}