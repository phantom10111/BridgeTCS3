#ifndef DEAL_HPP
#define DEAL_HPP

#include "model/Arbiter.hpp"
#include "model/ArbiterCycle.hpp"
#include "model/Bidding.hpp"
#include "model/DealResult.hpp"
#include "model/IPlayer.hpp"
#include "model/Play.hpp"

namespace model {

class Deal{
public:
	Deal(IPlayer&, IPlayer &, IPlayer &, IPlayer &);
	DealResult perform();
private:
	Bidding bidding;
	Play play;
	ArbiterCycle arbiters;
	void dealCards();
	void doBidding();
	int doPlay();
};

}

#endif
