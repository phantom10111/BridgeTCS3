#include "Trick.hpp"
#include "Card.hpp"
#include "Denomination.hpp"
#include <gtest/gtest.h>

TEST(TrickTest, OneColour)
{
	Trick t(Denomination::HEARTS);
	t.addCard(Card(Suit::DIAMOND, Rank::TEN));
	t.addCard(Card(Suit::DIAMOND, Rank::TWO));
	t.addCard(Card(Suit::DIAMOND, Rank::KING));
	t.addCard(Card(Suit::DIAMOND, Rank::QUEEN));
	ASSERT_EQ(2, t.getWinner());
}
TEST(TrickTest, TrumpBeat)
{
	Trick t(Denomination::SPADES);
	t.addCard(Card(Suit::CLUB, Rank::ACE));
	t.addCard(Card(Suit::CLUB, Rank::KING));
	t.addCard(Card(Suit::CLUB, Rank::QUEEN));
	t.addCard(Card(Suit::SPADE, Rank::TWO));
	ASSERT_EQ(3, t.getWinner());
}
TEST(TrickTest, TwoTrumps)
{
	Trick t(Denomination::DIAMONDS);
	t.addCard(Card(Suit::SPADE, Rank::ACE));
	t.addCard(Card(Suit::DIAMOND, Rank::TEN));
	t.addCard(Card(Suit::SPADE, Rank::TWO));
	t.addCard(Card(Suit::DIAMOND, Rank::JACK));
	ASSERT_EQ(3, t.getWinner());
}
TEST(TrickTest, WrongColour)
{
	Trick t(Denomination::CLUBS);
	t.addCard(Card(Suit::SPADE, Rank::TWO));
	t.addCard(Card(Suit::HEART, Rank::SEVEN));
	t.addCard(Card(Suit::DIAMOND, Rank::NINE));
	t.addCard(Card(Suit::HEART, Rank::THREE));
	ASSERT_EQ(0, t.getWinner());
}
