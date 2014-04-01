#include <gtest/gtest.h>
#include <vector>
#include "Card.hpp"
#include "Hand.hpp"

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

TEST(HandTest, HandTest)
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
