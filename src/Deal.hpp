#ifndef __DEAL_HPP
#define __DEAL_HPP

#include "Player.hpp"
#include "Result.hpp"
#include <algorithm>

class Deal{
private:
public:
	Deal(std::pair<Player, Player> first, std::pair<Player, Player> second);
	Result play();
};

#endif
