#ifndef GAME_HPP
#define GAME_HPP

#include "model/Deal.hpp"
#include "model/IPlayer.hpp"
#include "model/Result.hpp"

class Game
{
	Deal deal;

	public:
	Game(IPlayer &, IPlayer &, IPlayer &, IPlayer &);
	Result perform();
};

#endif
