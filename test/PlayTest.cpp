#include <gtest/gtest.h>
#include "Play.hpp"

TEST (PlayTest, HasNotEnded)
{
	Play p;
	p.setTrump(Denomination::VOID);
	
	ASSERT_FALSE(p.hasEnded());
}

TEST (PlayTest, RandomPlay)
{
	Play p;
	p.setTrump(Denomination::SPADES);
	
	p.receiveCard(Card(	Suit::CLUBS, 	Rank::ACE));
	
	ASSERT_EQ(p.getLeadingSuit(), Suit::CLUBS);
	
	p.receiveCard(Card(	Suit::CLUBS, 	Rank::THREE));
	p.receiveCard(Card(	Suit::CLUBS,	Rank::TEN));
	p.receiveCard(Card(	Suit::CLUBS, 	Rank::FOUR));
	

	p.receiveCard(Card(	Suit::SPADES, 	Rank::ACE));
	
	ASSERT_EQ(p.getLeadingSuit(), Suit::SPADES);
	
	p.receiveCard(Card(	Suit::SPADES, 	Rank::SEVEN));
	p.receiveCard(Card(	Suit::SPADES, 	Rank::TWO));
	p.receiveCard(Card(	Suit::SPADES, 	Rank::KING));
	
	
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::TWO));
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::EIGHT));
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::JACK));
	
	ASSERT_EQ(p.getLeadingSuit(), Suit::DIAMONDS);
	
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::ACE));
	
	
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::THREE));
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::SIX));
	
	ASSERT_EQ(p.getLeadingSuit(), Suit::DIAMONDS);
	
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::KING));
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::FIVE));
	
	
	p.receiveCard(Card(	Suit::HEARTS, 	Rank::ACE));

	ASSERT_EQ(p.getLeadingSuit(), Suit::HEARTS);

	p.receiveCard(Card(	Suit::HEARTS, 	Rank::FOUR));
	p.receiveCard(Card(	Suit::HEARTS, 	Rank::TWO));
	p.receiveCard(Card(	Suit::HEARTS, 	Rank::TEN));
	
	
	p.receiveCard(Card(	Suit::CLUBS, 	Rank::SIX));
	p.receiveCard(Card(	Suit::SPADES, 	Rank::FIVE));
	p.receiveCard(Card(	Suit::CLUBS, 	Rank::TWO));
	
	ASSERT_EQ(p.getLeadingSuit(), Suit::CLUBS);
	
	p.receiveCard(Card(	Suit::CLUBS, 	Rank::QUEEN));
	
	
	p.receiveCard(Card(	Suit::HEARTS, 	Rank::KING));
	p.receiveCard(Card(	Suit::HEARTS, 	Rank::THREE));
	p.receiveCard(Card(	Suit::HEARTS, 	Rank::QUEEN));

	ASSERT_EQ(p.getLeadingSuit(), Suit::HEARTS);

	p.receiveCard(Card(	Suit::HEARTS, 	Rank::FIVE));
	
	
	p.receiveCard(Card(	Suit::HEARTS, 	Rank::JACK));
	p.receiveCard(Card(	Suit::HEARTS, 	Rank::EIGHT));
	
	ASSERT_EQ(p.getLeadingSuit(), Suit::HEARTS);	
	
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::SEVEN));
	p.receiveCard(Card(	Suit::SPADES, 	Rank::JACK));
	
	
	p.receiveCard(Card(	Suit::CLUBS, 	Rank::SEVEN));
	
	ASSERT_EQ(p.getLeadingSuit(), Suit::CLUBS);
	
	p.receiveCard(Card(	Suit::SPADES, 	Rank::NINE));
	p.receiveCard(Card(	Suit::CLUBS, 	Rank::FIVE));
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::QUEEN));
	
	
	p.receiveCard(Card(	Suit::HEARTS, 	Rank::NINE));
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::FOUR));
	p.receiveCard(Card(	Suit::SPADES, 	Rank::THREE));
	p.receiveCard(Card(	Suit::CLUBS, 	Rank::EIGHT));
	
	p.receiveCard(Card(	Suit::SPADES, 	Rank::FOUR));
	p.receiveCard(Card(	Suit::SPADES, 	Rank::QUEEN));
	p.receiveCard(Card(	Suit::SPADES, 	Rank::TEN));
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::NINE));
	
	p.receiveCard(Card(	Suit::DIAMONDS, Rank::TEN));
	p.receiveCard(Card(	Suit::HEARTS,	Rank::SEVEN));
	p.receiveCard(Card(	Suit::CLUBS, 	Rank::JACK));
	p.receiveCard(Card(	Suit::SPADES, 	Rank::SIX));
	
	p.receiveCard(Card(	Suit::SPADES, 	Rank::EIGHT));
	p.receiveCard(Card(	Suit::CLUBS, 	Rank::NINE));
	p.receiveCard(Card(	Suit::HEARTS, 	Rank::SIX));
	p.receiveCard(Card(	Suit::CLUBS, 	Rank::KING));

	ASSERT_TRUE(p.hasEnded());
	ASSERT_EQ(p.getTricksWon(), 5);	
}
