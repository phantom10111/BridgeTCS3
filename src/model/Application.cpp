#include "model/Application.hpp"

namespace model
{

void Application::run()
{
	ui::text::ConsolePlayer consolePlayer(std::cin);
	RandomPlayer randomPlayer1(1), randomPlayer2(2), randomPlayer3(3);
	SingleDealGame tempGame(consolePlayer, randomPlayer1, randomPlayer2, randomPlayer3);
	game = &tempGame;
	sigModified(*this);
	game->perform();
}

}