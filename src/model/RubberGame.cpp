#include "model/DealResult.hpp"
#include "model/RubberGame.hpp"
#include "model/IPlayer.hpp"

//TODO Implement real functionality
namespace model {

RubberGame::RubberGame(IPlayer &player1, IPlayer &player2, IPlayer &player3, IPlayer &player4) :
	deal(player1, player2, player3, player4)
{
}

GameResult RubberGame::perform()
{
	deal.perform();
	return GameResult();
}

}
