#include <gtest/gtest.h>
#include "Card.hpp"
#include "BridgeDeck.hpp"

BridgeDeck d;
TEST(BridgeDeckTest, Zero){
	Card c= d.getCard();
	ASSERT_EQ(c.rank, Rank::ACE);
	ASSERT_EQ(c.suit, Suit::CLUBS);
} 
TEST(BridgeDeckTest, First){
	Card c= d.getCard();
	ASSERT_EQ(c.rank, Rank::KING);
	ASSERT_EQ(c.suit, Suit::CLUBS);
} 
TEST(BridgeDeckTest, THROWING){
	d.shuffle();
	
	for(int i=0; i<50; ++i){
		d.getCard();
	}
	ASSERT_THROW(d.getCard(), std::exception);
}
