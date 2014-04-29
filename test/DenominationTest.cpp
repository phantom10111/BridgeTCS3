#include <gtest/gtest.h>

#include "model/Denomination.hpp"

TEST(Denomination, Order)
{
	ASSERT_TRUE(Denomination::CLUBS < Denomination::DIAMONDS);
	ASSERT_TRUE(Denomination::CLUBS < Denomination::HEARTS);
	ASSERT_TRUE(Denomination::CLUBS < Denomination::SPADES);
	ASSERT_TRUE(Denomination::CLUBS < Denomination::VOID);
	ASSERT_TRUE(Denomination::DIAMONDS < Denomination::HEARTS);
	ASSERT_TRUE(Denomination::DIAMONDS < Denomination::SPADES);
	ASSERT_TRUE(Denomination::DIAMONDS < Denomination::VOID);
	ASSERT_TRUE(Denomination::HEARTS < Denomination::SPADES);
	ASSERT_TRUE(Denomination::HEARTS < Denomination::VOID);
	ASSERT_TRUE(Denomination::SPADES < Denomination::VOID);
}
