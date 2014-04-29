#include "model/Contract.hpp"

namespace model {

Contract::Contract(int level, Denomination denomination, int multiplier, int player) :
	level(level),
	denomination(denomination),
	multiplier(multiplier),
	player(player)
{ }

}
