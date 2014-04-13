#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "Arbiter.hpp"
#include "IPlayer.hpp"

using ::testing::_;
using ::testing::DoAll;
using ::testing::Ref;
using ::testing::Return;
using ::testing::SaveArg;
using ::testing::SaveArgPointee;

class MockPlayer : public IPlayer
{
public:
	MOCK_METHOD3(connectGameState, void(const std::vector<Card>&, const std::vector<Call>&, const std::vector<Trick>&));
	MOCK_METHOD1(connectDummyHand, void(const std::vector<Card>&));
	MOCK_METHOD0(getCard, Card());
	MOCK_METHOD0(getDummyCard, Card());
	MOCK_METHOD0(getCall, Call());
};

ACTION_P(Save0ArgRef, pointer){
	*pointer = &arg0;
}

class ArbiterTest : public ::testing::Test
{
protected:
	void testSameAndUnique(const std::vector<Card> &A, const std::vector<Card> &B) {											\
		ASSERT_EQ(A.size(), B.size());											
		for(Card ca : A){														
			int cnt = 0;														
			for(Card cb : B)													
				if(ca.suit == cb.suit && ca.rank == cb.rank)					
					++cnt;														
			ASSERT_EQ(cnt, 1);													
		}																		
	}
	void testCardAdding(Arbiter &arbiter, const std::vector<Card> &cards, Card card)
	{
		std::vector<Card> old = cards;
		old.push_back(card);
		arbiter.addCard(card);
		testSameAndUnique(old, cards);
	}
};

TEST_F(ArbiterTest, ArbiterConstructor)
{
	std::vector<Call> calls;
	std::vector<Trick> tricks;
	MockPlayer player;
	EXPECT_CALL(player, connectGameState(_, Ref(calls), Ref(tricks))).Times(1);
	Arbiter arbiter(player, calls, tricks);
}

TEST_F(ArbiterTest, ArbiterPassCardAddingToHand)
{
	std::vector<Call> calls;
	std::vector<Trick> tricks;
	MockPlayer player;
	const std::vector<Card> * cards = NULL;
	EXPECT_CALL(player, connectGameState(_, Ref(calls), Ref(tricks))).Times(1).WillOnce(Save0ArgRef(&cards));
	Arbiter arbiter(player, calls, tricks);
	testCardAdding(arbiter, *cards, Card(Suit::CLUBS, Rank::THREE));
	testCardAdding(arbiter, *cards, Card(Suit::SPADES, Rank::ACE));
	testCardAdding(arbiter, *cards, Card(Suit::HEARTS, Rank::NINE));
	testCardAdding(arbiter, *cards, Card(Suit::DIAMONDS, Rank::NINE));
	testCardAdding(arbiter, *cards, Card(Suit::CLUBS, Rank::FOUR));
	testCardAdding(arbiter, *cards, Card(Suit::HEARTS, Rank::ACE));
}

TEST_F(ArbiterTest, ArbiterPassDummyControl)
{
	std::vector<Call> calls;
	std::vector<Trick> tricks;

	MockPlayer playerA;
	const std::vector<Card> * cardsA = NULL;
	EXPECT_CALL(playerA, connectGameState(_, Ref(calls), Ref(tricks))).Times(1).WillOnce(Save0ArgRef(&cardsA));
	Arbiter arbiterA(playerA, calls, tricks);

	MockPlayer playerB;
	const std::vector<Card> * cardsB = NULL;
	EXPECT_CALL(playerB, connectGameState(_, Ref(calls), Ref(tricks))).Times(1).WillOnce(Save0ArgRef(&cardsB));
	Arbiter arbiterB(playerB, calls, tricks);

	const std::vector<Card> * cardsP = NULL;
	EXPECT_CALL(playerB, connectDummyHand(_)).Times(1).WillOnce(Save0ArgRef(&cardsP));
	Arbiter::passDummyControl(arbiterA, arbiterB);
	
	ASSERT_EQ(cardsP, cardsA);
}

TEST_F(ArbiterTest, ArbiterMakeCall)
{
	std::vector<Call> calls;
	std::vector<Trick> tricks;

	MockPlayer player;
	Call call = Call::BID(3, Denomination::CLUBS);
	EXPECT_CALL(player, connectGameState(_, Ref(calls), Ref(tricks))).Times(1);
	EXPECT_CALL(player, getCall()).Times(1).WillOnce(Return(call));
	
	Bidding bidding;
	
	Arbiter arbiter(player, calls, tricks);

	arbiter.makeCall(bidding);
	
	ASSERT_EQ(bidding.getCallsView().size(), 1);
	ASSERT_EQ(bidding.getCallsView()[0].level, call.level);
	ASSERT_EQ(bidding.getCallsView()[0].denomination, call.denomination);

	Call callA = Call::BID(2, Denomination::HEARTS);
	Call callB = Call::PASS();
	EXPECT_CALL(player, getCall()).Times(2).WillOnce(Return(callA)).WillOnce(Return(callB));
	
	arbiter.makeCall(bidding);
	ASSERT_EQ(bidding.getCallsView().size(), 2);
	ASSERT_EQ(bidding.getCallsView()[1].level, callB.level);
	ASSERT_EQ(bidding.getCallsView()[1].denomination, callB.denomination);
	
}

TEST_F(ArbiterTest, ArbiterMakeMove)
{
	std::vector<Call> calls;
	std::vector<Trick> tricks;

	MockPlayer player;
	Card card = Card(Suit::HEARTS, Rank::ACE);
	EXPECT_CALL(player, connectGameState(_, Ref(calls), Ref(tricks))).Times(1);
	EXPECT_CALL(player, getCard()).Times(1).WillOnce(Return(card));
	
	Play play;
	
	Arbiter arbiter(player, calls, tricks);
	arbiter.addCard(Card(Suit::HEARTS, Rank::ACE));
	arbiter.addCard(Card(Suit::SPADES, Rank::ACE));
	arbiter.addCard(Card(Suit::DIAMONDS, Rank::ACE));
	arbiter.addCard(Card(Suit::CLUBS, Rank::ACE));
	arbiter.addCard(Card(Suit::HEARTS, Rank::KING));
	arbiter.addCard(Card(Suit::SPADES, Rank::KING));
	arbiter.addCard(Card(Suit::DIAMONDS, Rank::KING));
	arbiter.addCard(Card(Suit::CLUBS, Rank::KING));

	arbiter.makeMove(play);
	
	ASSERT_EQ(play.getTricksView().size(), 1);
	ASSERT_EQ(play.getTricksView()[0].getCardsView().size(), 1);
	ASSERT_EQ(play.getTricksView()[0].getCardsView()[0].suit, Suit::HEARTS);
	ASSERT_EQ(play.getTricksView()[0].getCardsView()[0].rank, Rank::ACE);

	Card cardA = Card(Suit::DIAMONDS, Rank::ACE);
	Card cardB = Card(Suit::HEARTS, Rank::KING);
	EXPECT_CALL(player, getCard()).Times(2).WillOnce(Return(cardA)).WillOnce(Return(cardB));
	
	ASSERT_EQ(play.getTricksView().size(), 1);
	ASSERT_EQ(play.getTricksView()[0].getCardsView().size(), 2);
	ASSERT_EQ(play.getTricksView()[0].getCardsView()[1].suit, Suit::HEARTS);
	ASSERT_EQ(play.getTricksView()[0].getCardsView()[1].rank, Rank::KING);
}
