#include <gtest/gtest.h>

#include "Level.hpp"

TEST(Level, LevelEnum)
{
	ASSERT_TRUE((int) Level::TWO == 2);
	ASSERT_TRUE((int) Level::THREE == 3);
	ASSERT_TRUE((int) Level::FOUR == 4);
	ASSERT_TRUE((int) Level::FIVE == 5);
	ASSERT_TRUE((int) Level::SIX == 6);
	ASSERT_TRUE((int) Level::SEVEN == 7);
	ASSERT_TRUE((int) Level::EIGHT == 8);
	ASSERT_TRUE((int) Level::NINE == 9);
	ASSERT_TRUE((int) Level::TEN == 10);
	ASSERT_TRUE((int) Level::JACK == 11);
	ASSERT_TRUE((int) Level::QUEEN == 12);
	ASSERT_TRUE((int) Level::KING == 13);
	ASSERT_TRUE((int) Level::ACE == 14);
}
