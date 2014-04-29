#ifndef DEAL_HPP
#define DEAL_HPP

#include "Arbiter.hpp"
#include "Bidding.hpp"
#include "IPlayer.hpp"
#include "Play.hpp"
#include "Result.hpp"
#include "ArbiterCycle.hpp"

class Deal{
public:
	Deal(IPlayer&, IPlayer &, IPlayer &, IPlayer &);
	Result perform();
private:
	Bidding bidding;
	Play play;
	ArbiterCycle arbiters;
	void dealCards();
	void doBidding();
	void doPlay();
};

#endif
