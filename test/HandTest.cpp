#include <gtest/gtest.h>
#include <vector>
#include "model/Card.hpp"
#include "model/Hand.hpp"

class HandTest : public ::testing::Test
{
protected:
	void testSameAndUnique(const std::vector<model::Card> &A, const std::vector<model::Card> &B) {											\
		ASSERT_EQ(A.size(), B.size());											
		for(model::Card ca : A){														
			int cnt = 0;														
			for(model::Card cb : B)													
				if(ca.suit == cb.suit && ca.rank == cb.rank)					
					++cnt;
			ASSERT_EQ(cnt, 1);													
		}																		
	}

	void testCardAdding(model::Hand &hand, const std::vector<model::Card> &cards, model::Card card)
	{
		std::vector<model::Card> old = cards;
		old.push_back(card);
		hand.addCard(card);
		testSameAndUnique(old, cards);
	}

	void testCardRemoval(model::Hand &hand, const std::vector<model::Card> &cards, int k)
	{
		std::vector<model::Card> old = cards;
		hand.removeCard(old[k]);
		std::swap(old[k], old.back());
		old.pop_back();
		testSameAndUnique(old, cards);
	}
};

TEST_F(HandTest, HandTest)
{
	model::Hand hand;
	const std::vector<model::Card> &view = hand.getCardsView();
	testCardAdding(hand, view, model::Card(model::Suit::CLUBS, model::Rank::THREE));
	testCardAdding(hand, view, model::Card(model::Suit::SPADES, model::Rank::ACE));
	testCardAdding(hand, view, model::Card(model::Suit::HEARTS, model::Rank::NINE));
	testCardAdding(hand, view, model::Card(model::Suit::DIAMONDS, model::Rank::NINE));
	testCardRemoval(hand, view, 2);
	testCardRemoval(hand, view, 2);
	testCardAdding(hand, view, model::Card(model::Suit::CLUBS, model::Rank::FOUR));
	testCardAdding(hand, view, model::Card(model::Suit::HEARTS, model::Rank::ACE));
	testCardRemoval(hand, view, 1);
	ASSERT_EQ(&view, &hand.getCardsView());
}

TEST_F(HandTest, HandHasSuitTest)
{
	model::Hand hand;
	
	hand.addCard(model::Card(model::Suit::CLUBS, model::Rank::THREE));
	ASSERT_TRUE(hand.hasSuit(model::Suit::CLUBS));
	ASSERT_FALSE(hand.hasSuit(model::Suit::SPADES));
	ASSERT_FALSE(hand.hasSuit(model::Suit::HEARTS));
	ASSERT_FALSE(hand.hasSuit(model::Suit::DIAMONDS));
	hand.removeCard(model::Card(model::Suit::CLUBS, model::Rank::THREE));
	
	hand.addCard(model::Card(model::Suit::SPADES, model::Rank::THREE));
	ASSERT_FALSE(hand.hasSuit(model::Suit::CLUBS));
	ASSERT_TRUE(hand.hasSuit(model::Suit::SPADES));
	ASSERT_FALSE(hand.hasSuit(model::Suit::HEARTS));
	ASSERT_FALSE(hand.hasSuit(model::Suit::DIAMONDS));
	hand.removeCard(model::Card(model::Suit::SPADES, model::Rank::THREE));
	
	hand.addCard(model::Card(model::Suit::HEARTS, model::Rank::THREE));
	ASSERT_FALSE(hand.hasSuit(model::Suit::CLUBS));
	ASSERT_FALSE(hand.hasSuit(model::Suit::SPADES));
	ASSERT_TRUE(hand.hasSuit(model::Suit::HEARTS));
	ASSERT_FALSE(hand.hasSuit(model::Suit::DIAMONDS));
	hand.removeCard(model::Card(model::Suit::HEARTS, model::Rank::THREE));
	
	hand.addCard(model::Card(model::Suit::DIAMONDS, model::Rank::THREE));
	ASSERT_FALSE(hand.hasSuit(model::Suit::CLUBS));
	ASSERT_FALSE(hand.hasSuit(model::Suit::SPADES));
	ASSERT_FALSE(hand.hasSuit(model::Suit::HEARTS));
	ASSERT_TRUE(hand.hasSuit(model::Suit::DIAMONDS));
	hand.removeCard(model::Card(model::Suit::DIAMONDS, model::Rank::THREE));
	
}
