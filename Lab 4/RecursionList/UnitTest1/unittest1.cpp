#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\RecursionList\RecursionList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTestPallindrome)
	{
	public:

		TEST_METHOD(Loop1)
		{
			PallindromeByLoop calculator;

			Assert::IsTrue(calculator.isPallindrome("tacocat"));

		}

		TEST_METHOD(Loop2)
		{
			PallindromeByLoop calculator;

			// Should return false, since whitespace is considered in palindrome calculation
			Assert::IsFalse(calculator.isPallindrome("a nut for a jar of tuna"));
		}

		TEST_METHOD(Loop3)
		{
			PallindromeByLoop calculator;

			// Should return false, since an empty string is technically not a palindrome
			Assert::IsFalse(calculator.isPallindrome(""));
		}


		TEST_METHOD(Recursion1)
		{
			PallindromeByRecursion calculator;

			Assert::IsTrue(calculator.isPallindrome(0, 6, "tacocat"));
		}

		TEST_METHOD(Recursion2)
		{
			PallindromeByRecursion calculator;

			Assert::IsFalse(calculator.isPallindrome(0, 22, "a nut for a jar of tuna"));

		}

		TEST_METHOD(Recursion3)
		{
			PallindromeByRecursion calculator;

			Assert::IsFalse(calculator.isPallindrome(0, 0, ""));

		}

		TEST_METHOD(Stack1)
		{
			PallindromeByStack calculator;

			Assert::IsTrue(calculator.isPallindrome("tacocat"));

		}

		TEST_METHOD(Stack2)
		{
			PallindromeByStack calculator;

			Assert::IsFalse(calculator.isPallindrome("a nut for a jar of tuna"));


		}

		TEST_METHOD(Stack3)
		{
			PallindromeByStack calculator;

			Assert::IsFalse(calculator.isPallindrome(""));


		}

		TEST_METHOD(UserDefinedExceptionTest1)
		{

			std::string status = CallSimpleExceptionMethod(1);
			Assert::AreEqual(std::string("I got Exception 1"), status);

		}

		TEST_METHOD(UserDefinedExceptionTest2)
		{


			std::string status = CallSimpleExceptionMethod(2);
			Assert::AreEqual(std::string("I got Exception 2"), status);

		}

		TEST_METHOD(UserDefinedExceptionTest3)
		{

			std::string status = CallSimpleExceptionMethod(3);
			Assert::AreEqual(std::string("I got Exception 3"), status);

		}

		TEST_METHOD(UserDefinedExceptionTest4)
		{

			std::string status = CallSimpleExceptionMethod(4);
			Assert::AreEqual(std::string("I did not get an Exception"), status);

		}


	};
}