#ifndef DEAL_HPP
#define DEAL_HPP

#include "model/Arbiter.hpp"
#include "model/Bidding.hpp"
#include "model/IPlayer.hpp"
#include "model/Play.hpp"
#include "model/Result.hpp"
#include "model/ArbiterCycle.hpp"

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
