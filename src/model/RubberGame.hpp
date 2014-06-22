#ifndef RUBBER_GAME_HPP
#define RUBBER_GAME_HPP

#include "model/Deal.hpp"
#include "model/GameResult.hpp"
#include "model/IGame.hpp"
#include "model/IPlayer.hpp"

//TODO Implement real functionality
namespace model {

class RubberGame : public IGame, public ui::IObservable<RubberGame>
{
	Deal deal;

	public:
	RubberGame(RubberGame&) = delete;
	RubberGame(RubberGame&&) = delete;
	RubberGame(IPlayer &, IPlayer &, IPlayer &, IPlayer &);
	const Deal * getDeal() const {
		return &deal;
	}
	virtual GameResult perform();
};

}

#endif
