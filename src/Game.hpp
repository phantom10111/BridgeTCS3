#ifndef GAME_HPP
#define GAME_HPP

#include "Deal.hpp"

class Game
{
	Deal deal;

	public:
	Game(IPlayer &, IPlayer &, IPlayer &, IPlayer &);
	Result perform();
};

#endif
