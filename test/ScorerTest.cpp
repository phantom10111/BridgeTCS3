#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "model/DealResult.hpp"
#include "model/Denomination.hpp"
#include "model/GameResult.hpp"
#include "model/Scorer.hpp"
#include "Utilities.hpp"

using ::testing::_;
using ::testing::DoAll;
using ::testing::Ref;
using ::testing::Return;
using ::testing::SaveArg;
using ::testing::SaveArgPointee;

class ScorerTest : public ::testing::Test
{

};

TEST(ScorerTest, SimpleClubsWithDouble)
{
	model::Scorer scorer;

	model::DealResult dealResult( model::Contract(1, model::Denomination::CLUBS, 2 ,0), 7, 0, 0);
	ASSERT_FALSE(scorer.update(dealResult));
	model::GameResult gameResult = scorer.getResult();
	ASSERT_EQ(50, gameResult.over[0]);
	ASSERT_EQ(0, gameResult.over[1]);
	ASSERT_EQ(40, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);
	ASSERT_FALSE(scorer.update(dealResult));
	gameResult = scorer.getResult();
	ASSERT_EQ(100, gameResult.over[0]);
	ASSERT_EQ(0, gameResult.over[1]);
	ASSERT_EQ(80, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);	
	ASSERT_TRUE(scorer.update(dealResult));
	gameResult = scorer.getResult();
	ASSERT_EQ(270, gameResult.over[0]);
	ASSERT_EQ(0, gameResult.over[1]);
	ASSERT_EQ(0, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);	
	ASSERT_FALSE(scorer.update(dealResult));
	gameResult = scorer.getResult();
	ASSERT_EQ(320, gameResult.over[0]);
	ASSERT_EQ(0, gameResult.over[1]);
	ASSERT_EQ(40, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);
	ASSERT_FALSE(scorer.update(dealResult));
	gameResult = scorer.getResult();
	ASSERT_EQ(370, gameResult.over[0]);
	ASSERT_EQ(0, gameResult.over[1]);
	ASSERT_EQ(80, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);
	ASSERT_TRUE(scorer.update(dealResult));
	gameResult = scorer.getResult();
	ASSERT_EQ(1240, gameResult.over[0]);
	ASSERT_EQ(0, gameResult.over[1]);
	ASSERT_EQ(0, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);
}

TEST(ScorerTest, SimpleSlamBonud)
{
	model::Scorer scorer;

	model::DealResult dealResult( model::Contract(7, model::Denomination::NO_TRUMP, 4 ,0), 13, 0, 0);
	ASSERT_TRUE(scorer.update(dealResult));
	model::GameResult gameResult = scorer.getResult();
	ASSERT_EQ(1980, gameResult.over[0]);
	ASSERT_EQ(0, gameResult.over[1]);
	ASSERT_EQ(0, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);
	ASSERT_TRUE(scorer.update(dealResult));
	gameResult = scorer.getResult();
	ASSERT_EQ(5160, gameResult.over[0]);
	ASSERT_EQ(0, gameResult.over[1]);
	ASSERT_EQ(0, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);	
}

TEST(ScorerTest, SimpleHonorBonus)
{
	model::Scorer scorer;
	model::DealResult dealResult0(model::Contract(2, model::Denomination::HEARTS, 1 , 2), 10, 150, 0);
	ASSERT_FALSE(scorer.update(dealResult0));
	model::GameResult gameResult = scorer.getResult();
	ASSERT_EQ(60, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);
	ASSERT_EQ(150+2*30 , gameResult.over[0]);
	ASSERT_EQ(0 , gameResult.over[1]);
	
	model::DealResult dealResult1(model::Contract(1, model::Denomination::CLUBS, 2 , 3), 8, 0, 100);
	ASSERT_FALSE(scorer.update(dealResult1));
	gameResult=scorer.getResult();
	ASSERT_EQ(60, gameResult.under[0]);
	ASSERT_EQ(40, gameResult.under[1]);
	ASSERT_EQ(150+2*30, gameResult.over[0]);
	ASSERT_EQ(100+1*100+50, gameResult.over[1]);
}

TEST(ScorerTest, FullRuberGame)
{
	model::Scorer scorer;

	model::DealResult dealResultOne( model::Contract(2, model::Denomination::NO_TRUMP, 1 ,0), 9, 0, 0);
	ASSERT_FALSE(scorer.update(dealResultOne));
	model::GameResult gameResult = scorer.getResult();
	ASSERT_EQ(30, gameResult.over[0]);
	ASSERT_EQ(0, gameResult.over[1]);
	ASSERT_EQ(70, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);
	model::DealResult dealResultTwo( model::Contract(4, model::Denomination::HEARTS, 1 ,1), 10, 0, 0);
	ASSERT_TRUE(scorer.update(dealResultTwo));
	gameResult = scorer.getResult();
	ASSERT_EQ(100, gameResult.over[0]);
	ASSERT_EQ(120, gameResult.over[1]);
	ASSERT_EQ(0, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);
	model::DealResult dealResultThree( model::Contract(5, model::Denomination::CLUBS, 1 ,1), 9, 0, 0);
	ASSERT_FALSE(scorer.update(dealResultThree));
	gameResult = scorer.getResult();
	ASSERT_EQ(300, gameResult.over[0]);
	ASSERT_EQ(120, gameResult.over[1]);
	ASSERT_EQ(0, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);
	model::DealResult dealResultFour( model::Contract(4, model::Denomination::SPADES, 2 ,0), 11, 0, 0);
	ASSERT_TRUE(scorer.update(dealResultFour));
	gameResult = scorer.getResult();
	ASSERT_EQ(690, gameResult.over[0]);
	ASSERT_EQ(120, gameResult.over[1]);
	ASSERT_EQ(0, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);
	model::DealResult dealResultFive( model::Contract(3, model::Denomination::CLUBS, 1 ,0), 10, 0, 0);
	ASSERT_FALSE(scorer.update(dealResultFive));
	gameResult = scorer.getResult();
	ASSERT_EQ(710, gameResult.over[0]);
	ASSERT_EQ(120, gameResult.over[1]);
	ASSERT_EQ(60, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);
	model::DealResult dealResultSix( model::Contract(6, model::Denomination::DIAMONDS, 1 ,1), 12, 0, 150);
	ASSERT_TRUE(scorer.update(dealResultSix));
	gameResult = scorer.getResult();
	/* Won't pass right now because scorer doesn't count rubber bonus and honor bonus */
	ASSERT_EQ(770, gameResult.over[0]);
	ASSERT_EQ(1640, gameResult.over[1]);
	ASSERT_EQ(0, gameResult.under[0]);
	ASSERT_EQ(0, gameResult.under[1]);
}
