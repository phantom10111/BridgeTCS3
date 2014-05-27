#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "model/Arbiter.hpp"
#include "model/IPlayer.hpp"
#include "model/Play.hpp"
#include "IPlayerMock.hpp"
#include "Utilities.hpp"

using ::testing::_;
using ::testing::DoAll;
using ::testing::Ref;
using ::testing::Return;
using ::testing::SaveArg;
using ::testing::SaveArgPointee;

class ArbiterTest : public ::testing::Test
{
protected:
	void testSameAndUnique(const std::vector<model::Card> &A, const std::vector<model::Card> &B) {
		ASSERT_EQ(A.size(), B.size());
		for(model::Card ca : A){
			int cnt = 0;
			for(model::Card cb : B)
				if(ca.suit == cb.suit && ca.rank == cb.rank)
					++cnt;
			ASSERT_EQ(cnt, 1);
		}
	}
	void testCardAdding(model::Arbiter &arbiter, const std::vector<model::Card> &cards, model::Card card)
	{
		std::vector<model::Card> old = cards;
		old.push_back(card);
		arbiter.addCard(card);
		testSameAndUnique(old, cards);
	}
};

TEST_F(ArbiterTest, ArbiterConstructor)
{
	std::vector<model::Call> calls;
	model::Play::Tricks tricks;
	MockPlayer player;
	EXPECT_CALL(player, connectGameState(_, Ref(calls), Ref(tricks))).Times(1);
	model::Arbiter arbiter(player, calls, tricks);
}

TEST_F(ArbiterTest, ArbiterPassCardAddingToHand)
{
	std::vector<model::Call> calls;
	model::Play::Tricks tricks;
	MockPlayer player;
	const std::vector<model::Card> * cards = NULL;
	EXPECT_CALL(player, connectGameState(_, Ref(calls), Ref(tricks))).Times(1).WillOnce(Save0ArgRef(&cards));
	model::Arbiter arbiter(player, calls, tricks);
	testCardAdding(arbiter, *cards, model::Card(model::Suit::CLUBS, model::Rank::THREE));
	testCardAdding(arbiter, *cards, model::Card(model::Suit::SPADES, model::Rank::ACE));
	testCardAdding(arbiter, *cards, model::Card(model::Suit::HEARTS, model::Rank::NINE));
	testCardAdding(arbiter, *cards, model::Card(model::Suit::DIAMONDS, model::Rank::NINE));
	testCardAdding(arbiter, *cards, model::Card(model::Suit::CLUBS, model::Rank::FOUR));
	testCardAdding(arbiter, *cards, model::Card(model::Suit::HEARTS, model::Rank::ACE));
}

TEST_F(ArbiterTest, ArbiterPassDummyControl)
{
	std::vector<model::Call> calls;
	model::Play::Tricks tricks;

	MockPlayer playerA;
	const std::vector<model::Card> * cardsA = NULL;
	EXPECT_CALL(playerA, connectGameState(_, Ref(calls), Ref(tricks))).Times(1).WillOnce(Save0ArgRef(&cardsA));
	model::Arbiter arbiterA(playerA, calls, tricks);

	MockPlayer playerB;
	const std::vector<model::Card> * cardsB = NULL;
	EXPECT_CALL(playerB, connectGameState(_, Ref(calls), Ref(tricks))).Times(1).WillOnce(Save0ArgRef(&cardsB));
	model::Arbiter arbiterB(playerB, calls, tricks);

	const std::vector<model::Card> * cardsP = NULL;
	EXPECT_CALL(playerB, connectDummyHand(_)).Times(1).WillOnce(Save0ArgRef(&cardsP));
	arbiterB.connectDummyView(arbiterA);
	
	ASSERT_EQ(cardsP, cardsA);
}

TEST_F(ArbiterTest, ArbiterMakeCall)
{
	std::vector<model::Call> calls;
	model::Play::Tricks tricks;

	MockPlayer player;
	model::Call call = model::Call::BID(3, model::Denomination::CLUBS);
	EXPECT_CALL(player, connectGameState(_, Ref(calls), Ref(tricks))).Times(1);
	EXPECT_CALL(player, getCall()).Times(1).WillOnce(Return(call));
	
	model::Bidding bidding;
	
	model::Arbiter arbiter(player, calls, tricks);

	arbiter.makeCall(bidding);
	
	ASSERT_EQ(bidding.getCallsView().size(), 1);
	ASSERT_EQ(bidding.getCallsView()[0].level, call.level);
	ASSERT_EQ(bidding.getCallsView()[0].denomination, call.denomination);

	model::Call callA = model::Call::BID(2, model::Denomination::HEARTS);
	model::Call callB = model::Call::PASS();
	EXPECT_CALL(player, getCall()).Times(2).WillOnce(Return(callA)).WillOnce(Return(callB));
	
	arbiter.makeCall(bidding);
	ASSERT_EQ(bidding.getCallsView().size(), 2);
	ASSERT_EQ(bidding.getCallsView()[1].level, callB.level);
	ASSERT_EQ(bidding.getCallsView()[1].denomination, callB.denomination);
	
}

TEST_F(ArbiterTest, ArbiterMakeMove)
{
	std::vector<model::Call> calls;
	model::Play::Tricks tricks;

	MockPlayer player;
	model::Card card = model::Card(model::Suit::HEARTS, model::Rank::ACE);
	EXPECT_CALL(player, connectGameState(_, Ref(calls), Ref(tricks))).Times(1);
	EXPECT_CALL(player, getCard()).Times(1).WillOnce(Return(card));
	
	model::Play play(model::Denomination::CLUBS);
	
	model::Arbiter arbiter(player, calls, tricks);
	arbiter.addCard(model::Card(model::Suit::HEARTS, model::Rank::ACE));
	arbiter.addCard(model::Card(model::Suit::SPADES, model::Rank::ACE));
	arbiter.addCard(model::Card(model::Suit::DIAMONDS, model::Rank::ACE));
	arbiter.addCard(model::Card(model::Suit::CLUBS, model::Rank::ACE));
	arbiter.addCard(model::Card(model::Suit::HEARTS, model::Rank::KING));
	arbiter.addCard(model::Card(model::Suit::SPADES, model::Rank::KING));
	arbiter.addCard(model::Card(model::Suit::DIAMONDS, model::Rank::KING));
	arbiter.addCard(model::Card(model::Suit::CLUBS, model::Rank::KING));

	arbiter.makeMove(play);
	
	ASSERT_EQ(play.getTricksView().size(), 1);
	ASSERT_EQ(play.getTricksView().front().getCardsView().size(), 1);
	ASSERT_EQ(play.getTricksView().front().getCardsView()[0].suit, model::Suit::HEARTS);
	ASSERT_EQ(play.getTricksView().front().getCardsView()[0].rank, model::Rank::ACE);

	model::Card cardA = model::Card(model::Suit::DIAMONDS, model::Rank::ACE);
	model::Card cardB = model::Card(model::Suit::HEARTS, model::Rank::KING);
	EXPECT_CALL(player, getCard()).Times(2).WillOnce(Return(cardA)).WillOnce(Return(cardB));
	
	arbiter.makeMove(play);

	ASSERT_EQ(play.getTricksView().size(), 1);
	ASSERT_EQ(play.getTricksView().front().getCardsView().size(), 2);
	ASSERT_EQ(play.getTricksView().front().getCardsView()[1].suit, model::Suit::HEARTS);
	ASSERT_EQ(play.getTricksView().front().getCardsView()[1].rank, model::Rank::KING);
}
