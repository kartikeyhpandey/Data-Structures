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
		
		TEST_METHOD(Insert1)
		{
			PQueue myQueue;
			myQueue.insert(1);
			Assert::IsTrue(myQueue.size() == 1);
		}
		TEST_METHOD(SortedQueue)
		{
			PQueue myQueue;
			myQueue.insert(1);
			myQueue.insert(100);
			myQueue.sort();
			Assert::IsTrue(myQueue. == 1);
		}
	};
}
