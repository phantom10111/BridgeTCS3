#ifndef CONTRACT_HPP
#define CONTRACT_HPP

#include "model/Denomination.hpp"

namespace model {

struct Contract
{
	int level;
	Denomination denomination;
	int multiplier;
	int player;

	inline Contract(int level, Denomination, int multiplier, int player);
};

inline Contract::Contract(int level, Denomination denomination, int multiplier, int player) :
	level(level),
	denomination(denomination),
	multiplier(multiplier),
	player(player)
{ }

}

#endif
