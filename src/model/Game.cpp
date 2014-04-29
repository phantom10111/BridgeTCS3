#include "model/Game.hpp"
#include "model/IPlayer.hpp"
#include "model/Result.hpp"

namespace model {

Game::Game(IPlayer &player1, IPlayer &player2, IPlayer &player3, IPlayer &player4) :
	deal(player1, player2, player3, player4)
{
}

Result Game::perform()
{
	return deal.perform();
}

}
