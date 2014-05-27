#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include <vector>
#include "model/Call.hpp"
#include "model/Card.hpp"
#include "model/Play.hpp"
#include "model/Trick.hpp"

namespace model {

class IPlayer{
public:
	virtual void connectGameState(const std::vector<Card>& cardsView, const std::vector<Call>& callsView, const Play::Tricks & tricksView) = 0;
	virtual void connectDummyHand(const std::vector<Card>& cardsView) = 0;
	virtual Card getCard() = 0;
	virtual Card getDummyCard() = 0;
	virtual Call getCall() = 0;
};

}

#endif
