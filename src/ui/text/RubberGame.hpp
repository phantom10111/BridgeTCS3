#ifndef UI_TEXT_RUBBER_GAME_HPP
#define UI_TEXT_Rubber_GAME_HPP

#include <iostream>

#include "model/RubberGame.hpp"
#include "ui/text/Deal.hpp"

namespace ui {
namespace text {

class RubberGame
{
	bool started;
	Deal dealView;
public:
	void notify(const model::RubberGame& obj) {
		if(!started && obj.getDeal() != nullptr){
			started = true;
			obj.getDeal()->sigModified.connect(
				[this](model::Deal const & deal){dealView.notify(deal);}
			);
		}
	}
};

}
}

#endif
