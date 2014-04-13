#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "Arbiter.hpp"
#include "IPlayer.hpp"

using ::testing::_;
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
