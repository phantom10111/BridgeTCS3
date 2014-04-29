#include <gtest/gtest.h>

#include "model/Bidding.hpp"
#include "model/Call.hpp"
#include "model/Contract.hpp"
#include "model/Denomination.hpp"

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

TEST_F(BiddingTest, sevenVoid)
{
	Call call = Call::BID(7,Denomination::VOID);
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(DOUBLE));
	ASSERT_NO_THROW(bidding.getCall(DOUBLE));
	ASSERT_TRUE(bidding.canGetCall(REDOUBLE));
	ASSERT_NO_THROW(bidding.getCall(REDOUBLE));
	ASSERT_FALSE(bidding.canGetCall(DOUBLE));
	ASSERT_FALSE(bidding.canGetCall(REDOUBLE));
	call = Call::BID(5,Denomination::CLUBS);
	ASSERT_FALSE(bidding.canGetCall(call));
	ASSERT_TRUE(bidding.canGetCall(PASS));
}

TEST_F(BiddingTest, onlyPassAfterRedouble)
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
	ASSERT_FALSE(bidding.canGetCall(DOUBLE));
	ASSERT_FALSE(bidding.canGetCall(REDOUBLE));
	call = Call::BID(5,Denomination::CLUBS);
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
	ASSERT_EQ(2, contract.level);
	ASSERT_EQ(Denomination::CLUBS, contract.denomination);
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
	ASSERT_EQ(2, contract.level);
	ASSERT_EQ(Denomination::CLUBS, contract.denomination);
	ASSERT_EQ(1, contract.multiplier);
	ASSERT_EQ(3, contract.player);
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
	ASSERT_EQ(2, contract.level);
	ASSERT_EQ(Denomination::CLUBS, contract.denomination);
	ASSERT_EQ(2, contract.multiplier);
	ASSERT_EQ(0, contract.player);
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
	ASSERT_EQ(2, contract.level);
	ASSERT_EQ(Denomination::CLUBS, contract.denomination);
	ASSERT_EQ(4, contract.multiplier);
	ASSERT_EQ(0, contract.player);
}

TEST_F(BiddingTest, threeBids)
{
	Call call = Call::BID(2,Denomination::CLUBS);
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(!bidding.hasEnded());
	call = Call::BID(2,Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::HEARTS);	
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::VOID);
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
	Contract contract = bidding.getContract();
	ASSERT_EQ(5, contract.level);
	ASSERT_EQ(Denomination::VOID, contract.denomination);
	ASSERT_EQ(1, contract.multiplier);
	ASSERT_EQ(3, contract.player);
}

TEST_F(BiddingTest, threeBidsDouble)
{
	Call call = Call::BID(2,Denomination::CLUBS);
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(!bidding.hasEnded());
	call = Call::BID(2,Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::HEARTS);	
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::VOID);
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
	Contract contract = bidding.getContract();
	ASSERT_EQ(5, contract.level);
	ASSERT_EQ(Denomination::VOID, contract.denomination);
	ASSERT_EQ(2, contract.multiplier);
	ASSERT_EQ(3, contract.player);
}

TEST_F(BiddingTest, threeBidsDoubleRedouble)
{
	Call call = Call::BID(2,Denomination::CLUBS);
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(!bidding.hasEnded());
	call = Call::BID(2,Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::HEARTS);	
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::VOID);
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
	Contract contract = bidding.getContract();
	ASSERT_EQ(5, contract.level);
	ASSERT_EQ(Denomination::VOID, contract.denomination);
	ASSERT_EQ(4, contract.multiplier);
	ASSERT_EQ(3, contract.player);
}

TEST_F(BiddingTest, noRedoubleWithoutDouble)
{
	Call call = Call::BID(2,Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_FALSE(bidding.hasEnded());
	call = Call::BID(2,Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::HEARTS);	
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::VOID);
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
	Call call = Call::BID(2,Denomination::CLUBS);
	ASSERT_TRUE(!bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(!bidding.hasEnded());
	call = Call::BID(2,Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::HEARTS);	
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::VOID);
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
	ASSERT_NO_THROW(bidding.getCall(Call::BID(1, Denomination::CLUBS)));
	ASSERT_NO_THROW(bidding.getCall(Call::BID(2, Denomination::CLUBS)));
	ASSERT_NO_THROW(bidding.getCall(Call::DOUBLE()));
	ASSERT_NO_THROW(bidding.getCall(Call::BID(3, Denomination::CLUBS)));
	ASSERT_NO_THROW(bidding.getCall(Call::DOUBLE()));
	ASSERT_NO_THROW(bidding.getCall(Call::REDOUBLE()));
	ASSERT_NO_THROW(bidding.getCall(Call::BID(4, Denomination::CLUBS)));
	ASSERT_NO_THROW(bidding.getCall(Call::PASS()));
	ASSERT_NO_THROW(bidding.getCall(Call::PASS()));
	ASSERT_NO_THROW(bidding.getCall(Call::PASS()));
	ASSERT_TRUE(bidding.hasEnded());
	ASSERT_TRUE(bidding.isSuccessful());
	ASSERT_NO_THROW(bidding.getContract());
	Contract contract = bidding.getContract();
	ASSERT_EQ(4, contract.level);
	ASSERT_EQ(Denomination::CLUBS, contract.denomination);
	ASSERT_EQ(1, contract.multiplier);
	ASSERT_EQ(0, contract.player);
}

TEST_F(BiddingTest, longestBidding)
{
	Call call = Call::BID(2,Denomination::CLUBS);
	ASSERT_FALSE(bidding.hasEnded());
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	ASSERT_TRUE(!bidding.hasEnded());
	call = Call::BID(2,Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(2,Denomination::HEARTS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(2,Denomination::SPADES);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(2,Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(3,Denomination::CLUBS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(3,Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(3,Denomination::HEARTS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(3,Denomination::SPADES);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(3,Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(4,Denomination::CLUBS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(4,Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(4,Denomination::HEARTS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(4,Denomination::SPADES);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(4,Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::CLUBS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::HEARTS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::SPADES);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(5,Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(6,Denomination::CLUBS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(6,Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(6,Denomination::HEARTS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(6,Denomination::SPADES);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(6,Denomination::VOID);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(7,Denomination::CLUBS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(7,Denomination::DIAMONDS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(7,Denomination::HEARTS);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(7,Denomination::SPADES);
	ASSERT_TRUE(bidding.canGetCall(call));
	ASSERT_NO_THROW(bidding.getCall(call));
	call = Call::BID(7,Denomination::VOID);
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
	Contract contract = bidding.getContract();
	ASSERT_EQ(7, contract.level);
	ASSERT_EQ(Denomination::VOID, contract.denomination);
	ASSERT_EQ(4, contract.multiplier);
	ASSERT_EQ(1, contract.player);
}
