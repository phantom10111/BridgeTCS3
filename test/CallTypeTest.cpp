#include <gtest/gtest.h>

#include "CallType.hpp"

TEST(CallType, CallTypeEnum)
{
	ASSERT_TRUE((int) CallType::DECLARATION == 0);
	ASSERT_TRUE((int) CallType::DOUBLE == 1);
	ASSERT_TRUE((int) CallType::REDOUBLE == 2);
	ASSERT_TRUE((int) CallType::PASS == 3);
}
