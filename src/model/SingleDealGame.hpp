#ifndef GAME_HPP
#define GAME_HPP

#include "model/Deal.hpp"
#include "model/GameResult.hpp"
#include "model/IGame.hpp"
#include "model/IPlayer.hpp"

namespace model {

class SingleDealGame : public IGame
{
	Deal deal;

	public:
	SingleDealGame(IPlayer &, IPlayer &, IPlayer &, IPlayer &);
	virtual GameResult perform();
};

}

#endif
