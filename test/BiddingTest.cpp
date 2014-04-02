#include <gtest/gtest.h>

#include "Bidding.hpp"
#include "Call.hpp"
#include "Contract.hpp"
#include "Denomination.hpp"

#include <stdexcept>

class BiddingTest : public ::testing::Test
{
	protected:
	Bidding bidding;
	Call PASS = Call::PASS();
	Call DOUBLE = Call::DOUBLE();
	Call REDOUBLE = Call::REDOUBLE();
};

TEST_F(BiddingTest, simpleConditions)
{
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_THROW(bidding.isSuccessful(), std::runtime_error);
	ASSERT_THROW(bidding.getContract(), std::runtime_error);
}

TEST_F(BiddingTest, 4passes)
{
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.hasEnded());
	ASSERT_FALSE(bidding.isSuccessful());
}

TEST_F(BiddingTest, oneBidScenarioTest)
{
	Call call = Call::BID(2,Denomination::CLUBS);
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.hasEnded());
	ASSERT_TRUE(bidding.isSuccessful());
	ASSERT_NO_THROW(bidding.getContract());
	Contract contract = bidding.getContract();
	ASSERT_TRUE(contract.denomination == Denomination::CLUBS);
	ASSERT_TRUE(contract.level == 2);
	ASSERT_TRUE(contract.player == 0);
	ASSERT_TRUE(contract.multiplier == 1);
}


TEST_F(BiddingTest, oneBidScenarioTestFourthPlayerWins)
{
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	Call call = Call::BID(2,Denomination::CLUBS);
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.hasEnded());
	ASSERT_TRUE(bidding.isSuccessful());
	ASSERT_NO_THROW(bidding.getContract());
	Contract contract = bidding.getContract();
	ASSERT_TRUE(contract.denomination == Denomination::CLUBS);
	ASSERT_TRUE(contract.level == 2);
	ASSERT_TRUE(contract.player == 3);
	ASSERT_TRUE(contract.multiplier == 1);
}

TEST_F(BiddingTest, doubleTest)
{
	Call call = Call::BID(2,Denomination::CLUBS);
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(DOUBLE));
	ASSERT_NO_THROW(bidding.getCall(DOUBLE));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.hasEnded());
	ASSERT_TRUE(bidding.isSuccessful());
	ASSERT_NO_THROW(bidding.getContract());
	Contract contract = bidding.getContract();
	ASSERT_TRUE(contract.denomination == Denomination::CLUBS);
	ASSERT_TRUE(contract.level == 2);
	ASSERT_TRUE(contract.player == 0);
	ASSERT_TRUE(contract.multiplier == 2);
}

TEST_F(BiddingTest, doubleRedoubleTest)
{
	Call call = Call::BID(2,Denomination::CLUBS);
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(DOUBLE));
	ASSERT_NO_THROW(bidding.getCall(DOUBLE));
	ASSERT_TRUE(bidding.canGetCall(REDOUBLE));
	ASSERT_NO_THROW(bidding.getCall(REDOUBLE));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.hasEnded());
	ASSERT_TRUE(bidding.isSuccessful());
	ASSERT_NO_THROW(bidding.getContract());
	Contract contract = bidding.getContract();
	ASSERT_TRUE(contract.denomination == Denomination::CLUBS);
	ASSERT_TRUE(contract.level == 2);
	ASSERT_TRUE(contract.player == 0);
	ASSERT_TRUE(contract.multiplier == 4);
}
