#ifndef DEAL_HPP
#define DEAL_HPP

#include "Arbiter.hpp"
#include "Bidding.hpp"
#include "IPlayer.hpp"
#include "Play.hpp"
#include "Result.hpp"
#include "Cycler.hpp"

class Deal{
private:
	Bidding bidding;
	Play play;
	Cycler<Arbiter, 4> arbiters;
	void dealCards();
	void doBidding();
	void doPlay();
public:
	Deal(IPlayer&, IPlayer &, IPlayer &, IPlayer &);
	Result perform();
};

#endif
