#include <gtest/gtest.h>
#include "Play.hpp"

TEST (PlayTest, HasNotEnded)
{
	Play p(Denomination::HEARTS);
	ASSERT_FALSE(p.hasEnded());
}
