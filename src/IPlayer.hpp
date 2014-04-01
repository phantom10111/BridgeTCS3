#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include "Call.hpp"
#include "Card.hpp"
#include <vector>

class IPlayer{
public:
	virtual void connectGameState(const std::vector<Card>& cardsView, const std::vector<Call>& callsView, const std::vector<Trick>& tricksView) = 0;
	virtual Card getCard(const std::vector<Card>& cards) = 0;
	virtual Call getCall() = 0;
};

#endif
