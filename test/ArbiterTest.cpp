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

//  g++ -std=c++0x -pthread ArbiterTest.cpp ../src/Arbiter.cpp -I../src -lgmock -o ArbiterTest

ACTION_P(Save0ArgRef, pointer){
	*pointer = &arg0;
}

class MockPlayer : public IPlayer {
public:
	MOCK_METHOD3(connectGameState, void(const std::vector<Card>&, const std::vector<Call>&, const std::vector<Trick>&));
	MOCK_METHOD1(getCard, Card(const std::vector<Card>&));
	MOCK_METHOD0(getCall, Call());
};

TEST(ArbiterTest, ArbiterConstructor)
{
	std::vector<Call> calls;
	std::vector<Trick> tricks;
	MockPlayer player;
	EXPECT_CALL(player, connectGameState(_, Ref(calls), Ref(tricks))).Times(1);
	Arbiter a(player, calls, tricks);
}

TEST(ArbiterTest, ArbiterCardView)
{
	std::vector<Call> calls;
	std::vector<Trick> tricks;
	MockPlayer player;
	const std::vector<Card> * cards;
	EXPECT_CALL(player, connectGameState(_, Ref(calls), Ref(tricks))).Times(1).WillOnce(Save0ArgRef(&cards));
	Arbiter a(player, calls, tricks);
	Card c = Card(Suit::CLUBS, Rank::TWO);
	a.addCard(c);
	//TODO
}


int main(int argc, char** argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
