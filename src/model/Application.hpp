#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>
#include "ui/IObservable.hpp"
#include "ui/text/ConsolePlayer.hpp"
#include "model/SingleDealGame.hpp"
#include "model/RandomPlayer.hpp"

namespace model {

class Application : public ui::IObservable<Application>
{
public:
	void run();
	const SingleDealGame * getGame() const
	{
		return game;
	}
private:
	SingleDealGame* game = nullptr;
};

}

#endif
