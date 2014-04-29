#include <gtest/gtest.h>

#include "model/Bidding.hpp"
#include "model/Call.hpp"
#include "model/Contract.hpp"
#include "model/Denomination.hpp"

#include <stdexcept>

class BiddingTest : public ::testing::Test
{
	protected:
	model::Bidding bidding;
	model::Call PASS = model::Call::PASS();
	model::Call DOUBLE = model::Call::DOUBLE();
	model::Call REDOUBLE = model::Call::REDOUBLE();
};

TEST_F(BiddingTest, simpleConditions)
{
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_THROW(bidding.isSuccessful(), std::runtime_error);
	ASSERT_THROW(bidding.getContract(), std::runtime_error);
}

TEST_F(BiddingTest, sevenVoid)
{
	model::Call call = model::Call::BID(7,model::Denomination::VOID);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(DOUBLE));
	ASSERT_NO_THROW(bidding.getCall(DOUBLE));
	ASSERT_TRUE(bidding.canGetCall(REDOUBLE));
	ASSERT_NO_THROW(bidding.getCall(REDOUBLE));
	ASSERT_FALSE(bidding.canGetCall(DOUBLE));
	ASSERT_FALSE(bidding.canGetCall(REDOUBLE));
	call = model::Call::BID(5,model::Denomination::CLUBS);
	ASSERT_FALSE(bidding.canGetCall(call));
	ASSERT_TRUE(bidding.canGetCall(PASS));
}

TEST_F(BiddingTest, onlyPassAfterRedouble)
{
	model::Call call = model::Call::BID(2,model::Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(DOUBLE));
	ASSERT_NO_THROW(bidding.getCall(DOUBLE));
	ASSERT_TRUE(bidding.canGetCall(REDOUBLE));
	ASSERT_NO_THROW(bidding.getCall(REDOUBLE));
	ASSERT_FALSE(bidding.canGetCall(DOUBLE));
	ASSERT_FALSE(bidding.canGetCall(REDOUBLE));
	call = model::Call::BID(5,model::Denomination::CLUBS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_TRUE(bidding.canGetCall(PASS));
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
	model::Call call = model::Call::BID(2,model::Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.hasEnded());
	ASSERT_TRUE(bidding.isSuccessful());
	ASSERT_NO_THROW(bidding.getContract());
	model::Contract contract = bidding.getContract();
	ASSERT_EQ(2, contract.level);
	ASSERT_EQ(model::Denomination::CLUBS, contract.denomination);
	ASSERT_EQ(1, contract.multiplier);
	ASSERT_EQ(0, contract.player);
}


TEST_F(BiddingTest, oneBidScenarioTestFourthPlayerWins)
{
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	model::Call call = model::Call::BID(2,model::Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.hasEnded());
	ASSERT_TRUE(bidding.isSuccessful());
	ASSERT_NO_THROW(bidding.getContract());
	model::Contract contract = bidding.getContract();
	ASSERT_EQ(2, contract.level);
	ASSERT_EQ(model::Denomination::CLUBS, contract.denomination);
	ASSERT_EQ(1, contract.multiplier);
	ASSERT_EQ(3, contract.player);
}

TEST_F(BiddingTest, doubleTest)
{
	model::Call call = model::Call::BID(2,model::Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
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
	model::Contract contract = bidding.getContract();
	ASSERT_EQ(2, contract.level);
	ASSERT_EQ(model::Denomination::CLUBS, contract.denomination);
	ASSERT_EQ(2, contract.multiplier);
	ASSERT_EQ(0, contract.player);
}

TEST_F(BiddingTest, doubleRedoubleTest)
{
	model::Call call = model::Call::BID(2,model::Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
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
	model::Contract contract = bidding.getContract();
	ASSERT_EQ(2, contract.level);
	ASSERT_EQ(model::Denomination::CLUBS, contract.denomination);
	ASSERT_EQ(4, contract.multiplier);
	ASSERT_EQ(0, contract.player);
}

TEST_F(BiddingTest, threeBids)
{
	model::Call call = model::Call::BID(2,model::Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
	call = model::Call::BID(2,model::Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::HEARTS);	
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.hasEnded());
	ASSERT_TRUE(bidding.isSuccessful());
	ASSERT_NO_THROW(bidding.getContract());
	model::Contract contract = bidding.getContract();
	ASSERT_EQ(5, contract.level);
	ASSERT_EQ(model::Denomination::VOID, contract.denomination);
	ASSERT_EQ(1, contract.multiplier);
	ASSERT_EQ(3, contract.player);
}

TEST_F(BiddingTest, threeBidsDouble)
{
	model::Call call = model::Call::BID(2,model::Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
	call = model::Call::BID(2,model::Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::HEARTS);	
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
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
	model::Contract contract = bidding.getContract();
	ASSERT_EQ(5, contract.level);
	ASSERT_EQ(model::Denomination::VOID, contract.denomination);
	ASSERT_EQ(2, contract.multiplier);
	ASSERT_EQ(3, contract.player);
}

TEST_F(BiddingTest, threeBidsDoubleRedouble)
{
	model::Call call = model::Call::BID(2,model::Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
	call = model::Call::BID(2,model::Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::HEARTS);	
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
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
	model::Contract contract = bidding.getContract();
	ASSERT_EQ(5, contract.level);
	ASSERT_EQ(model::Denomination::VOID, contract.denomination);
	ASSERT_EQ(4, contract.multiplier);
	ASSERT_EQ(3, contract.player);
}

TEST_F(BiddingTest, noRedoubleWithoutDouble)
{
	model::Call call = model::Call::BID(2,model::Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
	call = model::Call::BID(2,model::Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::HEARTS);	
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_FALSE(bidding.canGetCall(REDOUBLE));
	ASSERT_THROW(bidding.getCall(REDOUBLE),std::runtime_error);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_THROW(bidding.isSuccessful(),std::runtime_error);
}

TEST_F(BiddingTest, noDoubleAfterDouble)
{
	model::Call call = model::Call::BID(2,model::Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
	call = model::Call::BID(2,model::Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::HEARTS);	
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));	
	ASSERT_TRUE(bidding.canGetCall(PASS));
	ASSERT_NO_THROW(bidding.getCall(PASS));
	ASSERT_TRUE(bidding.canGetCall(DOUBLE));
	ASSERT_NO_THROW(bidding.getCall(DOUBLE));
	ASSERT_FALSE(bidding.canGetCall(DOUBLE));
	ASSERT_THROW(bidding.getCall(DOUBLE),std::runtime_error);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_THROW(bidding.isSuccessful(),std::runtime_error);
}

TEST_F(BiddingTest, biddingAfterDoubleRedouble)
{
	ASSERT_NO_THROW(bidding.getCall(model::Call::BID(1, model::Denomination::CLUBS)));
	ASSERT_NO_THROW(bidding.getCall(model::Call::BID(2, model::Denomination::CLUBS)));
	ASSERT_NO_THROW(bidding.getCall(model::Call::DOUBLE()));
	ASSERT_NO_THROW(bidding.getCall(model::Call::BID(3, model::Denomination::CLUBS)));
	ASSERT_NO_THROW(bidding.getCall(model::Call::DOUBLE()));
	ASSERT_NO_THROW(bidding.getCall(model::Call::REDOUBLE()));
	ASSERT_NO_THROW(bidding.getCall(model::Call::BID(4, model::Denomination::CLUBS)));
	ASSERT_NO_THROW(bidding.getCall(model::Call::PASS()));
	ASSERT_NO_THROW(bidding.getCall(model::Call::PASS()));
	ASSERT_NO_THROW(bidding.getCall(model::Call::PASS()));
	ASSERT_TRUE(bidding.hasEnded());
	ASSERT_TRUE(bidding.isSuccessful());
	ASSERT_NO_THROW(bidding.getContract());
	model::Contract contract = bidding.getContract();
	ASSERT_EQ(4, contract.level);
	ASSERT_EQ(model::Denomination::CLUBS, contract.denomination);
	ASSERT_EQ(1, contract.multiplier);
	ASSERT_EQ(0, contract.player);
}

TEST_F(BiddingTest, longestBidding)
{
	model::Call call = model::Call::BID(2,model::Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
	call = model::Call::BID(2,model::Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(2,model::Denomination::HEARTS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(2,model::Denomination::SPADES);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(2,model::Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(3,model::Denomination::CLUBS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(3,model::Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(3,model::Denomination::HEARTS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(3,model::Denomination::SPADES);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(3,model::Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(4,model::Denomination::CLUBS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(4,model::Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(4,model::Denomination::HEARTS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(4,model::Denomination::SPADES);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(4,model::Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::CLUBS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::HEARTS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::SPADES);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(5,model::Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(6,model::Denomination::CLUBS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(6,model::Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(6,model::Denomination::HEARTS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(6,model::Denomination::SPADES);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(6,model::Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(7,model::Denomination::CLUBS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(7,model::Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(7,model::Denomination::HEARTS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(7,model::Denomination::SPADES);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = model::Call::BID(7,model::Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
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
	model::Contract contract = bidding.getContract();
	ASSERT_EQ(7, contract.level);
	ASSERT_EQ(model::Denomination::VOID, contract.denomination);
	ASSERT_EQ(4, contract.multiplier);
	ASSERT_EQ(1, contract.player);
}
