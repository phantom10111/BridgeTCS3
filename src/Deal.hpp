#ifndef DEAL_HPP
#define DEAL_HPP

#include "Arbiter.hpp"
#include "Bidding.hpp"
#include "IPlayer.hpp"
#include "Play.hpp"
#include "Result.hpp"

class Deal{
private:
	Bidding bidding;
	Play play;
	Arbiter N, E, S, W;
	void dealCards();
public:
	Deal(IPlayer&, IPlayer &, IPlayer &, IPlayer &);
	Result perform();
};

#endif
