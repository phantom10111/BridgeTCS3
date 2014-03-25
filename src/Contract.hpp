#ifndef _CONTRACT_HPP_
#define _CONTRACT_HPP_

#include "Denomination.hpp"

struct Contract
{
	int level;
	Denomination denomination;
	int multiplier;
	int player;

	Contract(int level, Denomination, int multiplier, int player);
};

#endif
