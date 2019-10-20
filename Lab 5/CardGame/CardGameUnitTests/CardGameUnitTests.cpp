#include "pch.h"
#include "CppUnitTest.h"
#include "..\CardGame\CardGame.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CardGameUnitTests
{

	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Card_GetRankSuit) {
			Card c = Card(2, "Spades");
			Assert::IsTrue(c.GetVal() == 2);
			Assert::IsTrue(c.GetSuit() == "Spades");
		}

		TEST_METHOD(Card_GetCardRankSuit) {
			Card c = Card("Diamonds", 13);

			Assert::IsTrue(c.GetSuit() == "Diamonds");
			Assert::IsTrue(c.GetVal() == 13);
		}

		TEST_METHOD(Card_SetSuit){
			Card C=Card("Diamonds",12);
			C.SetSuit("Club");
			Assert::IsTrue(C.GetSuit() == "Club");
		}

		TEST_METHOD(Game_Start) {
			Game myGame;

			Assert::IsNotNull(myGame.player1);
			Assert::IsNotNull(myGame.player2);
			Assert::IsNotNull(myGame.deck);
			Assert::IsNotNull(myGame.currentPlayer);
		}
		
		TEST_METHOD(Game_CardToPileCheck){
			Game myGame;
			int deckCount = myGame.deck->GetSize();

			Assert::AreEqual(myGame.currentPlayer->GetNumCards(), 5);
			myGame.CardToPile(1);
			Assert::AreEqual(myGame.currentPlayer->GetNumCards(), 4);
			Assert::AreEqual(myGame.deck->GetSize(), deckCount + 1);
		}

		TEST_METHOD(Game_RedrawCheck){
			Game myGame;
			myGame.RedrawHand(myGame.currentPlayer);
			Assert::AreEqual(myGame.player1->GetNumCards(), 5);
		}

		TEST_METHOD(Person_NameCheck1){
			Person person1("Joe");
			Assert::IsTrue(person1.GetName() == "Joe");
			Assert::IsFalse(person1.GetName() == "Mama");
		}

		TEST_METHOD(Person_NameCheck2){
			Person person2("Mama");
			Assert::IsTrue(person2.GetName() == "Mama");
			Assert::IsFalse(person2.GetName() == "Joe");
		}

		TEST_METHOD(Person_AddCard){
			Person person1("Joe");
			Card* c = new Card("Hearts", 1);
			Assert::IsTrue(person1.AddCard(c));
			
			delete c;
		}

		TEST_METHOD(Deck_DeckConstructorCheck){
			Deck myDeck;
			Assert::IsTrue(myDeck.GetSize() == 52);
		}

		TEST_METHOD(Deck_DeckDeconstructorCheck){
			Deck myDeck;
			Assert::IsTrue(myDeck.GetSize() == 52);
			myDeck.~Deck();
			Assert::IsTrue(myDeck.GetSize() == 0);
		}

		TEST_METHOD(Deck_DeckGetSizeCheck){
			Deck myDeck;
			Assert::IsTrue(myDeck.GetSize() == 52);
		}
	};
}
