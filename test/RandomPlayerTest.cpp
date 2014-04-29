#include <gtest/gtest.h>
#include "RandomPlayer.hpp"

const int seed = 444;

TEST (RandomPlayerTest, EventuallyPasses)
{
	RandomPlayer rp(seed);
	const int limit = 30;
	for(int i = 0;i<limit;i++)
		if(rp.getCall().type == CallType::PASS)
			return;
	FAIL();
}

TEST (RandomPlayerTest, EventuallyPlaysRightCard)
{
	RandomPlayer rp(seed);
	const int limit = 500;
	for(int i = 0;i<limit;i++)
		if(rp.getCard() == Card(Suit::SPADES, Rank::ACE))
			return;
	FAIL();
}