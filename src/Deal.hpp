#ifndef DEAL_HPP
#define DEAL_HPP

#include "IPlayer.hpp"
#include "Result.hpp"

class Deal{
private:
	void dealCards();
public:
	Deal(IPlayer&, IPlayer &, IPlayer &, IPlayer &);
	Result play();
};

#endif
