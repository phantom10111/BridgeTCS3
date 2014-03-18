#ifndef _CONTRACT_HPP_
#define _CONTRACT_HPP_

#include "Denomination.hpp"
#include "Level.hpp"

struct Contract
{
	int level;
	Denomination denomination;
	int multiplier;
	int player;
};

#endif
