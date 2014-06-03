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
	int trickSize;
public:
	Play() : trickSize(-1) {}
	void notify(model::Play const & obj) {
		if(obj.getTricksView().back().getCardsView().size() != trickSize){
			std::cout << "Current trick: ";
			Printer::print(obj.getTricksView().back());
			std::cout << std::endl;
			trickSize = obj.getTricksView().back().getCardsView().size();
		}
	}
};

}
}

#endif
