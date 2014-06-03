#include "model/Application.hpp"
#include <random>

namespace model
{

void Application::run()
{
	ui::text::ConsolePlayer consolePlayer(std::cin);
	RandomPlayer<std::random_device> randomPlayer1, randomPlayer2, randomPlayer3;
	SingleDealGame tempGame(consolePlayer, randomPlayer1, randomPlayer2, randomPlayer3);
	game = &tempGame;
	sigModified(*this);
	game->perform();
}

}
