#ifndef IPLAYER_MOCK_HPP
#define IPLAYER_MOCK_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "model/Card.hpp"
#include "model/Call.hpp"
#include "model/Trick.hpp"
#include "model/IPlayer.hpp"

class MockPlayer : public IPlayer
{
public:
	MOCK_METHOD3(connectGameState, void(const std::vector<Card>&, const std::vector<Call>&, const std::vector<Trick>&));
	MOCK_METHOD1(connectDummyHand, void(const std::vector<Card>&));
	MOCK_METHOD0(getCard, Card());
	MOCK_METHOD0(getDummyCard, Card());
	MOCK_METHOD0(getCall, Call());
};

#endif
