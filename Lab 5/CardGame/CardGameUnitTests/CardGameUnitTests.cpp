#include "pch.h"
#include "CppUnitTest.h"
#include "..\CardGame\CardGame.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CardGameUnitTests
{

	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Card_getRankSuit) {
			Card c = Card(2, "Spades");
			Assert::IsTrue(c.GetVal() == 2);
			Assert::IsTrue(c.GetSuit() == "Spades");
		}

		TEST_METHOD(Card_getCardRankSuit) {
			Card c = Card("Diamonds", 13);

			Assert::IsTrue(c.GetSuit() == "Diamonds");
			Assert::IsTrue(c.GetVal() == 13);
		}

		TEST_METHOD(Game_Start) {
			Game myGame();
		}
	};
}
