#include <gtest/gtest.h>

#include "Bidding.hpp"
#include "Denomination.hpp"

TEST(BIDDING, simpleHasEndedTest)
{
	Bidding bidding;
	ASSERT_TRUE(!bidding.hasEnded());
}

TEST(BIDDING, oneBidScenarioTest)
{
	Bidding bidding;
	Call call = Call::BID(2,Denomination::CLUBS);
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	bidding.getCall(call);
	ASSERT_TRUE(!bidding.hasEnded());
	Call passCall = Call::PASS();
	ASSERT_TRUE(bidding.canGetCall(passCall));
	bidding.getCall(call);
	ASSERT_TRUE(bidding.canGetCall(passCall));
	bidding.getCall(call);	
	ASSERT_TRUE(bidding.canGetCall(passCall));
	bidding.getCall(call);
	ASSERT_TRUE(bidding.hasEnded());	
	Contract contract = bidding.getContract();
	ASSERT_TRUE(contract.denomination == Denomination::CLUBS);
	ASSERT_TRUE(contract.level == 2);
}
