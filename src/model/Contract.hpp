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


	Contract(int level, Denomination, int multiplier, int player);
};

}

#endif
