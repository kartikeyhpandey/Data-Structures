#include "pch.h"
#include "..\PQueueDLL\Heap.h"
#include "..\PQueueDLL\PQueue.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PQueueUnitTests
{
	TEST_CLASS(PQueueUnitTests)
	{
	public:
		
		TEST_METHOD(Insert)
		{
			PQueue myQueue;
			myQueue.insert(1);
			myQueue.insert(2);
			myQueue.insert(3);
			myQueue.insert(4);
			string print = myQueue.print();
			string compare = "1 2 3 4";
			Assert::IsTrue(print.compare(compare));
			Assert::IsTrue(myQueue.size() == 4);
		}
		TEST_METHOD(Remove)
		{
			PQueue myQueue;
			myQueue.insert(1);
			myQueue.insert(2);
			myQueue.insert(3);
			myQueue.insert(4);
			myQueue.remove();
			string print = myQueue.print();
			string comp = "1 2 3";
			Assert::IsTrue(print.compare(comp));
			Assert::IsTrue(myQueue.size() == 3);
			myQueue.remove();
			print = myQueue.print();
			comp = "1 2";
			Assert::IsTrue(print.compare(comp));
			Assert::IsTrue(myQueue.size() == 2);
			myQueue.remove();
			print = myQueue.print();
			comp = "1";
			Assert::IsTrue(print.compare(comp));
			Assert::IsTrue(myQueue.size() == 1);
		}
		TEST_METHOD(SortedQueue)
		{
			PQueue myQueue;
			myQueue.insert(3);
			myQueue.insert(1);
			myQueue.insert(2);
			myQueue.insert(4);
			myQueue.sort();
			string print = myQueue.print();
			string comp = "1 2 3 4";

			Assert::IsTrue(print.compare(comp));
		}
		TEST_METHOD(HeapInsert)
		{
			Heap myHeap;
			myHeap.insert(1);
			myHeap.insert(2);
			myHeap.insert(3);
			myHeap.insert(4);
			string print = myHeap.printHeap();
			Assert::IsTrue(print.compare("1 2 3 4"));
			Assert::IsTrue(myHeap.getCurrentSize() == 4);
		}
		TEST_METHOD(HeapInsert2)
		{
			Heap myHeap;
			myHeap.insert(1);
			myHeap.insert(2);
			myHeap.insert(3);
			myHeap.insert(4);
			string print = myHeap.printHeap();
			Assert::IsTrue(print.compare( "1 2 3 4"));
			Assert::IsTrue(myHeap.getCurrentSize() == 4);
		}
		TEST_METHOD(HeapRemove)
		{
			Heap myHeap;
			myHeap.insert(1);
			myHeap.insert(2);
			myHeap.insert(3);
			myHeap.insert(4);
			myHeap.remove();
			string print = myHeap.printHeap();
			Assert::IsTrue(print.compare("1 2 3"));
			Assert::IsTrue(myHeap.getCurrentSize() == 3);
		}
		TEST_METHOD(HeapInsert3)
		{
			Heap myHeap;
			myHeap.insert(1);
			myHeap.insert(2);
			myHeap.insert(3);
			myHeap.insert(4);
			myHeap.maxHeap();
			string print = myHeap.printHeap();
			Assert::IsTrue(print.compare( "4 3 2 1"));
			Assert::IsTrue(myHeap.getCurrentSize() == 4);
		}
	};
}
