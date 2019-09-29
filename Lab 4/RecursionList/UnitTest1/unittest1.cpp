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

			Assert::IsTrue(calculator.isPallindrome("pop"));

		}

		TEST_METHOD(Loop2)
		{
			PallindromeByLoop calculator;

			Assert::IsFalse(calculator.isPallindrome("push"));
		}

		TEST_METHOD(Loop3)
		{
			PallindromeByLoop calculator;

			Assert::IsFalse(calculator.isPallindrome(""));
		}

	
		TEST_METHOD(Recursion1)
		{
			PallindromeByRecursion calculator;

			Assert::IsTrue(calculator.isPallindrome("pop"));
		}

		TEST_METHOD(Recursion2)
		{
			PallindromeByRecursion calculator;

			Assert::IsFalse(calculator.isPallindrome("push"));

		}
		
		TEST_METHOD(Stack1)
		{
			PallindromeByStack calculator;

			Assert::IsTrue(calculator.isPallindrome("pop"));

		}

		TEST_METHOD(Stack2)
		{
			PallindromeByStack calculator;

			Assert::IsFalse(calculator.isPallindrome("push"));


		}
		
		TEST_METHOD(UserDefinedException1)
		{

			try
			{
				SimpleExceptionMethod(1);
				//Did not throw exception
				Assert::Fail();
			}
			//TODO you will need to uncommment the catch block below to catch you exceptions
			catch (MyException)
				{
					//Good 
				}
			catch (std::exception e)
			{
				//Bad Did not catch user defined exceptio
				Assert::Fail();
			}


			try
			{
				SimpleExceptionMethod(-1);
				//Did not throw exception
				Assert::Fail();
			}
				catch (MyException )
				{
					//Good 
				}
			catch (std::exception e)
			{
				//Bad Did not catch user defined exception
				Assert::Fail();
			}
			
		}
		
		
	};
}