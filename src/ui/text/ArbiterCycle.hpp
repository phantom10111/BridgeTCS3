#ifndef UI_TEXT_ARBITER_CYCLE_HPP
#define UI_TEXT_ARBITER_CYCLE_HPP

#include <iostream>

#include "model/ArbiterCycle.hpp"

namespace ui {
namespace text {

class ArbiterCycle
{
private:
	int activePlayer;
public:
	ArbiterCycle() : activePlayer(-1) {}
	void notify(const model::ArbiterCycle& obj)
	{
		activePlayer = obj.getIndex();
	}
	int const & getActivePlayerView()
	{
		return activePlayer;
	}
};

}
}

#endif
