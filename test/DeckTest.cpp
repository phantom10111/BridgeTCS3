#include <gtest/gtest.h>
#include "Card.hpp"
#include "BridgeDeck.hpp"

BridgeDeck d;
TEST(FactorialTest, Zero){
	Card c= d.getCard();
	ASSERT_EQ(c.rank, Rank::ACE);
	ASSERT_EQ(c.suit, Suit::CLUBS);
} 
TEST(FactorialTest, First){
	Card c= d.getCard();
	ASSERT_EQ(c.rank, Rank::KING);
	ASSERT_EQ(c.suit, Suit::CLUBS);
} 
TEST(FactorialTest, THROWING){
	d.shuffle();
	
	for(int i=0; i<52; ++i){
		d.getCard();
	}
	ASSERT_THROW(d.getCard(), std::exception);
}
