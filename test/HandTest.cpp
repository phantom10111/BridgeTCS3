#include <gtest/gtest.h>
#include <vector>
#include "model/Card.hpp"
#include "model/Hand.hpp"

class HandTest : public ::testing::Test
{
protected:
	void testSameAndUnique(const std::vector<Card> &A, const std::vector<Card> &B) {											\
		ASSERT_EQ(A.size(), B.size());											
		for(Card ca : A){														
			int cnt = 0;														
			for(Card cb : B)													
				if(ca.suit == cb.suit && ca.rank == cb.rank)					
					++cnt;
			ASSERT_EQ(cnt, 1);													
		}																		
	}

	void testCardAdding(Hand &hand, const std::vector<Card> &cards, Card card)
	{
		std::vector<Card> old = cards;
		old.push_back(card);
		hand.addCard(card);
		testSameAndUnique(old, cards);
	}

	void testCardRemoval(Hand &hand, const std::vector<Card> &cards, int k)
	{
		std::vector<Card> old = cards;
		hand.removeCard(old[k]);
		std::swap(old[k], old.back());
		old.pop_back();
		testSameAndUnique(old, cards);
	}
};

TEST_F(HandTest, HandTest)
{
	Hand hand;
	const std::vector<Card> &view = hand.getCardsView();
	testCardAdding(hand, view, Card(Suit::CLUBS, Rank::THREE));
	testCardAdding(hand, view, Card(Suit::SPADES, Rank::ACE));
	testCardAdding(hand, view, Card(Suit::HEARTS, Rank::NINE));
	testCardAdding(hand, view, Card(Suit::DIAMONDS, Rank::NINE));
	testCardRemoval(hand, view, 2);
	testCardRemoval(hand, view, 2);
	testCardAdding(hand, view, Card(Suit::CLUBS, Rank::FOUR));
	testCardAdding(hand, view, Card(Suit::HEARTS, Rank::ACE));
	testCardRemoval(hand, view, 1);
	ASSERT_EQ(&view, &hand.getCardsView());
}

TEST_F(HandTest, HandHasSuitTest)
{
	Hand hand;
	
	hand.addCard(Card(Suit::CLUBS, Rank::THREE));
	ASSERT_EQ(hand.hasSuit(Suit::CLUBS), true);
	ASSERT_EQ(hand.hasSuit(Suit::SPADES), false);
	ASSERT_EQ(hand.hasSuit(Suit::HEARTS), false);
	ASSERT_EQ(hand.hasSuit(Suit::DIAMONDS), false);
	hand.removeCard(Card(Suit::CLUBS, Rank::THREE));
	
	hand.addCard(Card(Suit::SPADES, Rank::THREE));
	ASSERT_EQ(hand.hasSuit(Suit::CLUBS), false);
	ASSERT_EQ(hand.hasSuit(Suit::SPADES), true);
	ASSERT_EQ(hand.hasSuit(Suit::HEARTS), false);
	ASSERT_EQ(hand.hasSuit(Suit::DIAMONDS), false);
	hand.removeCard(Card(Suit::SPADES, Rank::THREE));
	
	hand.addCard(Card(Suit::HEARTS, Rank::THREE));
	ASSERT_EQ(hand.hasSuit(Suit::CLUBS), false);
	ASSERT_EQ(hand.hasSuit(Suit::SPADES), false);
	ASSERT_EQ(hand.hasSuit(Suit::HEARTS), true);
	ASSERT_EQ(hand.hasSuit(Suit::DIAMONDS), false);
	hand.removeCard(Card(Suit::HEARTS, Rank::THREE));
	
	hand.addCard(Card(Suit::DIAMONDS, Rank::THREE));
	ASSERT_EQ(hand.hasSuit(Suit::CLUBS), false);
	ASSERT_EQ(hand.hasSuit(Suit::SPADES), false);
	ASSERT_EQ(hand.hasSuit(Suit::HEARTS), false);
	ASSERT_EQ(hand.hasSuit(Suit::DIAMONDS), true);
	hand.removeCard(Card(Suit::DIAMONDS, Rank::THREE));
	
}
