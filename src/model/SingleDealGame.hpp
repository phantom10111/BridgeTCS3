#ifndef SINGLE_GAME_HPP
#define SINGLE_GAME_HPP

#include "model/Deal.hpp"
#include "model/GameResult.hpp"
#include "model/IGame.hpp"
#include "model/IPlayer.hpp"

namespace model {

class SingleDealGame : public IGame, public ui::IObservable<SingleDealGame>
{
	Deal deal;

	public:
	SingleDealGame(SingleDealGame&) = delete;
	SingleDealGame(SingleDealGame&&) = delete;
	SingleDealGame(IPlayer &, IPlayer &, IPlayer &, IPlayer &);
	const Deal * getDeal() const {
		return &deal;
	}
	virtual GameResult perform();
};

}

#endif
