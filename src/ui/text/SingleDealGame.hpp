#ifndef UI_TEXT_SINGLE_DEAL_GAME_HPP
#define UI_TEXT_SINGLE_DEAL_GAME_HPP

#include <iostream>

#include "model/SingleDealGame.hpp"
#include "ui/text/Deal.hpp"

namespace ui {
namespace text {

class SingleDealGame
{
	bool started;
	Deal dealView;
public:
	void notify(const model::SingleDealGame& obj) {
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
