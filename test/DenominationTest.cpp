#include <gtest/gtest.h>

#include "model/Denomination.hpp"

TEST(Denomination, Order)
{
	ASSERT_TRUE(model::Denomination::CLUBS < model::Denomination::DIAMONDS);
	ASSERT_TRUE(model::Denomination::CLUBS < model::Denomination::HEARTS);
	ASSERT_TRUE(model::Denomination::CLUBS < model::Denomination::SPADES);
	ASSERT_TRUE(model::Denomination::CLUBS < model::Denomination::VOID);
	ASSERT_TRUE(model::Denomination::DIAMONDS < model::Denomination::HEARTS);
	ASSERT_TRUE(model::Denomination::DIAMONDS < model::Denomination::SPADES);
	ASSERT_TRUE(model::Denomination::DIAMONDS < model::Denomination::VOID);
	ASSERT_TRUE(model::Denomination::HEARTS < model::Denomination::SPADES);
	ASSERT_TRUE(model::Denomination::HEARTS < model::Denomination::VOID);
	ASSERT_TRUE(model::Denomination::SPADES < model::Denomination::VOID);
}
