#include "Trick.hpp"
#include "Card.hpp"
#include "Denomination.hpp"
#include <gtest/gtest.h>

TEST(TrickTest, OneColour)
{
	Trick t(Denomination::HEARTS);
	t.addCard(Card(Suit::DIAMONDS, Rank::TEN));
	t.addCard(Card(Suit::DIAMONDS, Rank::TWO));
	t.addCard(Card(Suit::DIAMONDS, Rank::KING));
	t.addCard(Card(Suit::DIAMONDS, Rank::QUEEN));
	ASSERT_EQ(2, t.getWinner());
}
TEST(TrickTest, TrumpBeat)
{
	Trick t(Denomination::SPADES);
	t.addCard(Card(Suit::CLUBS, Rank::ACE));
	t.addCard(Card(Suit::CLUBS, Rank::KING));
	t.addCard(Card(Suit::CLUBS, Rank::QUEEN));
	t.addCard(Card(Suit::SPADES, Rank::TWO));
	ASSERT_EQ(3, t.getWinner());
}
TEST(TrickTest, TwoTrumps)
{
	Trick t(Denomination::DIAMONDS);
	t.addCard(Card(Suit::SPADES, Rank::ACE));
	t.addCard(Card(Suit::DIAMONDS, Rank::TEN));
	t.addCard(Card(Suit::SPADES, Rank::TWO));
	t.addCard(Card(Suit::DIAMONDS, Rank::JACK));
	ASSERT_EQ(3, t.getWinner());
}
TEST(TrickTest, WrongColour)
{
	Trick t(Denomination::CLUBS);
	t.addCard(Card(Suit::SPADES, Rank::TWO));
	t.addCard(Card(Suit::HEARTS, Rank::SEVEN));
	t.addCard(Card(Suit::DIAMONDS, Rank::NINE));
	t.addCard(Card(Suit::HEARTS, Rank::THREE));
	ASSERT_EQ(0, t.getWinner());
}
