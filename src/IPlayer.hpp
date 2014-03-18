#ifndef __IPLAYER_HPP
#define __IPLAYER_HPP

#include "Call.hpp"
#include "Card.hpp"
#include <vector>

class IPlayer{
public:
	IPlayer() = 0;
	void connectGameState(const std::vector<Card>& cards) = 0;
	Card getCard(const std::vector<Card>& cards) = 0;
	Call getCall() = 0;
};

#endif
