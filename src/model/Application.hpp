#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>
#include "ui/IObservable.hpp"
#include "ui/text/ConsolePlayer.hpp"
#include "model/RubberGame.hpp"
#include "model/RandomPlayer.hpp"

namespace model {

class Application : public ui::IObservable<Application>
{
public:
	Application() = default;
	Application(Application&) = delete;
	Application(Application&&) = delete;
	void run();
	const RubberGame * getGame() const
	{
		return game;
	}
private:
	RubberGame* game = nullptr;
};

}

#endif
