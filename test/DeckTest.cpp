#include <gtest/gtest.h>
#include "model/Card.hpp"
#include "model/BridgeDeck.hpp"

TEST(BridgeDeckTest, Zero){
	model::BridgeDeck d;
	model::Card c= d.getCard();
	ASSERT_EQ(c.rank, model::Rank::ACE);
	ASSERT_EQ(c.suit, model::Suit::CLUBS);
} 
TEST(BridgeDeckTest, First){
	model::BridgeDeck d;
	model::Card c= d.getCard();
	c= d.getCard();
	ASSERT_EQ(c.rank, model::Rank::KING);
	ASSERT_EQ(c.suit, model::Suit::CLUBS);
} 
TEST(BridgeDeckTest, THROWING){
	model::BridgeDeck d;
	d.shuffle();
	
	for(int i=0; i<52; ++i){
		d.getCard();
	}
	ASSERT_THROW(d.getCard(), std::exception);
}
