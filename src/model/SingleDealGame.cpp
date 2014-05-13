#include "model/DealResult.hpp"
#include "model/SingleDealGame.hpp"
#include "model/IPlayer.hpp"

namespace model {

SingleDealGame::SingleDealGame(IPlayer &player1, IPlayer &player2, IPlayer &player3, IPlayer &player4) :
	deal(player1, player2, player3, player4)
{
}

GameResult SingleDealGame::perform()
{
	deal.perform();
	return GameResult();
}

}
