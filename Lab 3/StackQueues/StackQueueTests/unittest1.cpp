#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "..\StackQueues\StackQueues.h"


namespace StackQueueTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(StackTests_IsEmpty1)
		{
			ArrayBasedStack stack;
			Assert::IsTrue(stack.isEmpty());
		}

		TEST_METHOD(StackTests_IsEmpty2)
		{
			ArrayBasedStack stack;
			Assert::IsTrue(stack.isEmpty());
			Assert::IsTrue(stack.push(4));

			Assert::IsFalse(stack.isEmpty());
			Assert::IsTrue(stack.push(3));

			Assert::IsFalse(stack.isEmpty());
			Assert::IsTrue(stack.push(2));

			Assert::IsFalse(stack.isEmpty());
			Assert::IsTrue(stack.push(1));

			Assert::IsFalse(stack.isEmpty());

		}

		TEST_METHOD(StackTests_IsEmpty3)
		{
			ArrayBasedStack stack;
			Assert::IsTrue(stack.isEmpty());
			Assert::IsTrue(stack.push(4));

			Assert::IsFalse(stack.isEmpty());
			Assert::IsTrue(stack.push(3));

			Assert::IsFalse(stack.isEmpty());

			Assert::IsTrue(stack.pop());
			Assert::IsFalse(stack.isEmpty());

			Assert::IsTrue(stack.pop());
			Assert::IsTrue(stack.isEmpty());

		}

		TEST_METHOD(StackTests_PushAndPeek1)
		{
			ArrayBasedStack stack;
			Assert::IsTrue(stack.isEmpty());
			try
			{
				int val = stack.peek();
				Assert::Fail();
			}
			catch (...)
			{
				//Assuming right exception was thrown
			}

		}

		TEST_METHOD(StackTests_PushAndPeek2)
		{
			ArrayBasedStack stack;
			Assert::IsTrue(stack.isEmpty());
			Assert::IsTrue(stack.push(4));
			Assert::AreEqual(4, stack.peek());

			Assert::IsFalse(stack.isEmpty());
			Assert::IsTrue(stack.push(3));
			Assert::AreEqual(3, stack.peek());

			Assert::IsFalse(stack.isEmpty());
			Assert::IsTrue(stack.push(2));
			Assert::AreEqual(2, stack.peek());

			Assert::IsFalse(stack.isEmpty());
			Assert::IsTrue(stack.push(1));
			Assert::AreEqual(1, stack.peek());

		}
		
		TEST_METHOD(StackTests_Pop)
		{
			ArrayBasedStack stack;
			Assert::IsTrue(stack.isEmpty());
			Assert::IsTrue(stack.push(4));
			Assert::IsFalse(stack.isEmpty());
			Assert::IsTrue(stack.push(3));
			Assert::IsFalse(stack.isEmpty());
			Assert::IsTrue(stack.push(2));
			Assert::IsFalse(stack.isEmpty());
			Assert::IsTrue(stack.push(1));
			Assert::IsFalse(stack.isEmpty());

			Assert::AreEqual(1, stack.peek());
			Assert::IsTrue(stack.pop());
			Assert::IsFalse(stack.isEmpty());
			Assert::AreEqual(2, stack.peek());
			Assert::IsTrue(stack.pop());
			Assert::IsFalse(stack.isEmpty());
			Assert::AreEqual(3, stack.peek());
			Assert::IsTrue(stack.pop());
			Assert::IsFalse(stack.isEmpty());
			Assert::AreEqual(4, stack.peek());
			Assert::IsTrue(stack.pop());

			Assert::IsTrue(stack.isEmpty());

			Assert::IsFalse(stack.pop());
		}

		TEST_METHOD(StackTests_Pop2)
		{
			ArrayBasedStack stack;
			Assert::IsTrue(stack.isEmpty());
			Assert::IsFalse(stack.pop());

		}

		TEST_METHOD(QueueTests_IsEmpty1)
		{
			ArrayBasedQueue queue;
			Assert::IsTrue(queue.isEmpty());
		}

		TEST_METHOD(QueueTests_IsEmpty2)
		{
			ArrayBasedQueue queue;
			Assert::IsTrue(queue.isEmpty());
			Assert::IsTrue(queue.enQueue("1,1,2"));
			Assert::IsFalse(queue.isEmpty());
			Assert::IsTrue(queue.enQueue("2,1,3"));
			Assert::IsFalse(queue.isEmpty());
		}

		TEST_METHOD(QueueTests_IsEmpty3)
		{
			ArrayBasedQueue queue;
			Assert::IsTrue(queue.isEmpty());
			Assert::IsTrue(queue.enQueue("1,1,2"));
			Assert::IsFalse(queue.isEmpty());
			Assert::IsTrue(queue.enQueue("2,1,3"));
			Assert::IsFalse(queue.isEmpty());

			Assert::AreEqual(std::string("1,1,2"), queue.peekFront());
			Assert::IsTrue(queue.deQueue());
			Assert::IsFalse(queue.isEmpty());
			Assert::AreEqual(std::string("2,1,3"), queue.peekFront());
			Assert::IsTrue(queue.deQueue());
			Assert::IsTrue(queue.isEmpty());

		}



		TEST_METHOD(QueueTests_EnQueue_PeekFront1)
		{
			ArrayBasedQueue queue;
			Assert::IsTrue(queue.isEmpty());
			Assert::IsTrue(queue.enQueue("1,1,2"));
			Assert::AreEqual(std::string("1,1,2"), queue.peekFront());
			Assert::IsFalse(queue.isEmpty());

			Assert::IsTrue(queue.enQueue("2,1,3"));
			Assert::AreEqual(std::string("1,1,2"), queue.peekFront());
			Assert::IsFalse(queue.isEmpty());

			Assert::IsTrue(queue.enQueue("1,2,3"));
			Assert::AreEqual(std::string("1,1,2"), queue.peekFront());
			Assert::IsFalse(queue.isEmpty());

			Assert::IsTrue(queue.enQueue("3,1,2"));
			Assert::AreEqual(std::string("1,1,2"), queue.peekFront());
			Assert::IsFalse(queue.isEmpty());

		}


		TEST_METHOD(QueueTests_PeekFront2)
		{
			ArrayBasedQueue queue;
			Assert::IsTrue(queue.isEmpty());
			try
			{
				std::string val = queue.peekFront();
				Assert::Fail();
			}
			catch (...)
			{
				//Assuming right exception was thrown
			}

		}

		TEST_METHOD(QueueTests_DeQueue1)
		{
			ArrayBasedQueue queue;
			Assert::IsTrue(queue.isEmpty());
			Assert::IsTrue(queue.enQueue("1,1,2"));
			Assert::IsFalse(queue.isEmpty());
			Assert::IsTrue(queue.enQueue("2,1,3"));
			Assert::IsFalse(queue.isEmpty());
			Assert::IsTrue(queue.enQueue("1,2,3"));
			Assert::IsFalse(queue.isEmpty());
			Assert::IsTrue(queue.enQueue("3,1,2"));
			Assert::IsFalse(queue.isEmpty());

			Assert::AreEqual(std::string("1,1,2"), queue.peekFront());
			Assert::IsTrue(queue.deQueue());
			Assert::IsFalse(queue.isEmpty());
			Assert::AreEqual(std::string("2,1,3"), queue.peekFront());
			Assert::IsTrue(queue.deQueue());
			Assert::IsFalse(queue.isEmpty());
			Assert::AreEqual(std::string("1,2,3"), queue.peekFront());
			Assert::IsTrue(queue.deQueue());
			Assert::IsFalse(queue.isEmpty());
			Assert::AreEqual(std::string("3,1,2"), queue.peekFront());
			Assert::IsTrue(queue.deQueue());

			Assert::IsTrue(queue.isEmpty());

			Assert::IsFalse(queue.deQueue());

		}

	};
}