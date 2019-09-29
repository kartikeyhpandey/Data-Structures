#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Lab01DLL\Lab01DLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab01Test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Deck_GetCard_1)
		{
			Deck deck;

			Card card1 = deck.GetCard(HEARTS,1);
			Card card2 = deck.GetCard(SPADES,11);

			Assert::AreEqual(1, card1.GetRank());
			Assert::AreEqual(11, card2.GetRank());

			// this  code should work, https://developercommunity.visualstudio.com/content/problem/175181/native-unit-tests-assertareequal-gives-compile-err.html
			//Assert::AreEqual(HEARTS, card1.GetSuit());
			//Assert::AreEqual(SPADES, card2.GetSuit());

			// So going to convert to int
			Assert::AreEqual((int)HEARTS, (int)card1.GetSuit());
			Assert::AreEqual((int)SPADES, (int)card2.GetSuit());
		}

		TEST_METHOD(Deck_GetCard_2)
		{
			Deck deck;

			Card card1 = deck.GetCard(DIAMONDS, 12);
			Card card2 = deck.GetCard(CLUBS, 3);

			Assert::AreEqual(12, card1.GetRank());
			Assert::AreEqual(3, card2.GetRank());

			// this  code should work, https://developercommunity.visualstudio.com/content/problem/175181/native-unit-tests-assertareequal-gives-compile-err.html
			//Assert::AreEqual(HEARTS, card1.GetSuit());
			//Assert::AreEqual(SPADES, card2.GetSuit());

			// So going to convert to int
			Assert::AreEqual((int)DIAMONDS, (int)card1.GetSuit());
			Assert::AreEqual((int)CLUBS, (int)card2.GetSuit());
		}


		TEST_METHOD(Deck_GetCard_BoundsChecking1)
		{
			Deck deck;
			 

			try
			{
				Card card1 = deck.GetCard(DIAMONDS, 122);
				Assert::Fail();
			}
			catch (...)
			{
				//Assume exception is correct, technically we should make our own exception for this
			}
		}

		TEST_METHOD(Deck_GetCard_BoundsChecking2)
		{
			Deck deck;

			try
			{
				Card card1 = deck.GetCard(DIAMONDS, -122);
				Assert::Fail();
			}
			catch (...)
			{
				//Assume exception is correct, technically we should make our own exception for this
			}
		}


		TEST_METHOD(BlackJackHand_ScoreHand_1)
		{
			Deck deck;

			Card card1 = deck.GetCard(HEARTS, 1);
			Card card2 = deck.GetCard(SPADES, 11);

			BlackJackHand blackJackHand;

			blackJackHand.AddCard(card1);
			blackJackHand.AddCard(card2);

			int score = blackJackHand.ScoreHand();
			Assert::AreEqual(21, score);
		}

		TEST_METHOD(BlackJackHand_ScoreHand_2)
		{
			Deck deck;

			Card card1 = deck.GetCard(HEARTS, 1);
			Card card2 = deck.GetCard(SPADES, 1);
			Card card3 = deck.GetCard(CLUBS, 1);
			Card card4 = deck.GetCard(DIAMONDS, 1);

			BlackJackHand blackJackHand;

			blackJackHand.AddCard(card1);
			blackJackHand.AddCard(card2);
			blackJackHand.AddCard(card3);
			blackJackHand.AddCard(card4);

			int score = blackJackHand.ScoreHand();
			Assert::AreEqual(14, score);
		}

		TEST_METHOD(BlackJackHand_ScoreHand_3)
		{
			Deck deck;

			Card card1 = deck.GetCard(HEARTS, 11);
			Card card2 = deck.GetCard(SPADES, 11);
			Card card3 = deck.GetCard(CLUBS, 11);
			Card card4 = deck.GetCard(DIAMONDS, 11);

			BlackJackHand blackJackHand;

			blackJackHand.AddCard(card1);
			blackJackHand.AddCard(card2);
			blackJackHand.AddCard(card3);
			blackJackHand.AddCard(card4);

			int score = blackJackHand.ScoreHand();
			Assert::AreEqual(-1, score);
		}

		TEST_METHOD(BlackJackHand_ScoreHand_4)
		{
			Deck deck;

			Card card1 = deck.GetCard(HEARTS, 2);
			Card card2 = deck.GetCard(SPADES, 4);
			Card card3 = deck.GetCard(CLUBS, 11);

			BlackJackHand blackJackHand;

			blackJackHand.AddCard(card1);
			blackJackHand.AddCard(card2);
			blackJackHand.AddCard(card3);

			int score = blackJackHand.ScoreHand();
			Assert::AreEqual(16, score);
		}

	};
}