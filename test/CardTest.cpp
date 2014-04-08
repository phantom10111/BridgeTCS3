#include <gtest/gtest.h>
#include "../src/Card.hpp"

TEST(CardTest, RankEnum)
{
	ASSERT_TRUE(Rank::TWO < Rank::THREE);
	ASSERT_TRUE(Rank::THREE < Rank::FOUR);
	ASSERT_TRUE(Rank::FOUR < Rank::FIVE);
	ASSERT_TRUE(Rank::FIVE < Rank::SIX);
	ASSERT_TRUE(Rank::SIX < Rank::SEVEN);
	ASSERT_TRUE(Rank::SEVEN < Rank::EIGHT);
	ASSERT_TRUE(Rank::EIGHT < Rank::NINE);
	ASSERT_TRUE(Rank::NINE < Rank::TEN);
	ASSERT_TRUE(Rank::TEN < Rank::JACK);
	ASSERT_TRUE(Rank::JACK < Rank::QUEEN);
	ASSERT_TRUE(Rank::QUEEN < Rank::KING);
	ASSERT_TRUE(Rank::KING < Rank::ACE);
}
