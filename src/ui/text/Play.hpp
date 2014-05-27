#ifndef UI_TEXT_PLAY_HPP
#define UI_TEXT_PLAY_HPP

#include <iostream>

#include "model/Play.hpp"
#include "ui/text/Printer.hpp"

namespace ui {
namespace text {

class Play
{
private:
	int const &activePlayer;
	int trickSize;
public:
	Play(int const & activePlayer) : trickSize(-1), activePlayer(activePlayer) {}
	void notify(model::Play const & obj) {
		if(obj.getTricksView().back().getCardsView().size() != trickSize){
			std::cout << "Player #" << activePlayer << " plays: ";
			Printer::print(obj.getTricksView().back().getCardsView().back());
			std::cout << std::endl;
			trickSize = obj.getTricksView().back().getCardsView().size();
		}
	}
};

}
}

#endif
