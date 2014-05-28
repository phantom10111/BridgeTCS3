#include <gtest/gtest.h>
#include "model/RandomPlayer.hpp"

const int seed = 444;

TEST (RandomPlayerTest, EventuallyPasses)
{
	model::RandomPlayer<std::mt19937> rp(seed);
	const int limit = 30;
	for(int i = 0;i<limit;i++)
		if(rp.getCall().type == model::CallType::PASS)
			return;
	FAIL();
}

TEST (RandomPlayerTest, EventuallyPlaysRightCard)
{
	model::RandomPlayer<std::mt19937> rp(seed);
	const int limit = 500;
	for(int i = 0;i<limit;i++)
		if(rp.getCard() == model::Card(model::Suit::SPADES, model::Rank::ACE))
			return;
	FAIL();
}
