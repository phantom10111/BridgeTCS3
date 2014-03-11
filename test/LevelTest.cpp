#include <gtest/gtest.h>

#include "Level.hpp"

TEST(Level, LevelEnum)
{
	ASSERT_TRUE(Level::TWO < Level::THREE);
	ASSERT_TRUE(Level::THREE < Level::FOUR);
	ASSERT_TRUE(Level::FOUR < Level::FIVE);
	ASSERT_TRUE(Level::FIVE < Level::SIX);
	ASSERT_TRUE(Level::SIX < Level:SEVEN);
	ASSERT_TRUE(Level::SEVEN < Level::EIGHT);
	ASSERT_TRUE(Level::EIGHT < Level::NINE);
	ASSERT_TRUE(Level::NINE < Level::TEN);
	ASSERT_TRUE(Level::TEN < Level::JACK);
	ASSERT_TRUE(Level::JACK < Level::QUEEN);
	ASSERT_TRUE(Level::QUEEN < Level::KING);
	ASSERT_TRUE(Level::KING < Level::ACE);
}
