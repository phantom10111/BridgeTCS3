#ifndef IPLAYER_MOCK_HPP
#define IPLAYER_MOCK_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "model/Card.hpp"
#include "model/Call.hpp"
#include "model/Trick.hpp"
#include "model/IPlayer.hpp"
#include "model/Play.hpp"

class MockPlayer : public model::IPlayer
{
public:
	MOCK_METHOD3(connectGameState, void(const std::vector<model::Card>&, const std::vector<model::Call>&, const model::Play::Tricks &));
	MOCK_METHOD1(connectDummyHand, void(const std::vector<model::Card>&));
	MOCK_METHOD0(getCard, model::Card());
	MOCK_METHOD0(getDummyCard, model::Card());
	MOCK_METHOD0(getCall, model::Call());
};

#endif
