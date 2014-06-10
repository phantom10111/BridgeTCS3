#ifndef UI_TEXT_APPLICATION_HPP
#define UI_TEXT_APPLICATION_HPP

#include <iostream>

#include "model/Application.hpp"
#include "ui/text/RubberGame.hpp"

namespace ui {
namespace text {

class Application
{
	bool started = false;
	RubberGame gameView;
public:
	void notify(const model::Application& obj) {
		if(!started && obj.getGame() != nullptr){
			started = true;
			obj.getGame()->sigModified.connect(
				[this](model::RubberGame const & game){gameView.notify(game);}
			);
			gameView.notify(*obj.getGame());
		}
	}
};

}
}

#endif
