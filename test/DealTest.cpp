#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "model/Deal.hpp"
#include "model/IPlayer.hpp"
#include "IPlayerMock.hpp"
#include "Utilities.hpp"

using ::testing::_;
using ::testing::DoAll;
using ::testing::Ref;
using ::testing::Return;
using ::testing::SaveArg;
using ::testing::SaveArgPointee;

TEST(DealTest, DealDealCards)
{
	MockPlayer playerA, playerB, playerC, playerD;
	const std::vector<Card> *cardsA, *cardsB, *cardsC, *cardsD;
	EXPECT_CALL(playerA, connectGameState(_, _, _)).Times(1).WillOnce(Save0ArgRef(&cardsA));
	EXPECT_CALL(playerB, connectGameState(_, _, _)).Times(1).WillOnce(Save0ArgRef(&cardsB));
	EXPECT_CALL(playerC, connectGameState(_, _, _)).Times(1).WillOnce(Save0ArgRef(&cardsC));
	EXPECT_CALL(playerD, connectGameState(_, _, _)).Times(1).WillOnce(Save0ArgRef(&cardsD));

	EXPECT_CALL(playerA, getCall()).Times(1).WillOnce(Return(Call::PASS()));
	EXPECT_CALL(playerB, getCall()).Times(1).WillOnce(Return(Call::PASS()));
	EXPECT_CALL(playerC, getCall()).Times(1).WillOnce(Return(Call::PASS()));
	EXPECT_CALL(playerD, getCall()).Times(1).WillOnce(Return(Call::PASS()));

	Deal deal(playerA, playerB, playerC, playerD);

	deal.perform();
	
	ASSERT_EQ(cardsA->size(), 13);
	ASSERT_EQ(cardsB->size(), 13);
	ASSERT_EQ(cardsC->size(), 13);
	ASSERT_EQ(cardsD->size(), 13);
}
