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
				Card c = Card(2, 12);
				Assert::IsTrue(c.getRank() == 12);
				Assert::IsTrue(c.getSuit() == 2);
			}

			TEST_METHOD(Card_getCardRankSuit) {
				Card c = Card(4, 13);

				Assert::IsTrue(c.getCardSuit() == "C");
				Assert::IsTrue(c.getCardRank() == " K");
			}

			TEST_METHOD(Card_getCard_outofrange) {
				Card c = Card(5, 14);

				Assert::IsTrue(c.getCardSuit() == " ");
				Assert::IsTrue(c.getCardRank() == "  ");
			}

			TEST_METHOD(Deck_initial) {
				Deck d = Deck(); //calls reload

				Assert::IsTrue(d.cardsInDeck() == 52);
			}

			TEST_METHOD(Deck_loadDraw) {
				Deck d = Deck();
				Card* c = new Card(2, 6);

				d.load(c);
				Card* cc = d.draw();

				Assert::IsTrue(d.cardsInDeck() == 52);
				Assert::IsTrue(c->getRank() == cc->getRank());
				Assert::IsTrue(c->getSuit() == cc->getSuit());
			}

		};
}
