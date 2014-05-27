#ifndef UI_TEXT_BIDDING_HPP
#define UI_TEXT_BIDDING_HPP

#include <iostream>

#include "model/Bidding.hpp"
#include "ui/text/Printer.hpp"

namespace ui {
namespace text {

class Bidding
{
private:
	int callsCount;
	int const &activePlayer;
public:
	Bidding(int const & activePlayer) : callsCount(0), activePlayer(activePlayer) {}
	void notify(model::Bidding const & obj) {
		if(obj.getCallsView().size() != callsCount){
			callsCount = obj.getCallsView().size();
			std::cout << "Player #" << activePlayer << " calls: ";
			Printer::print(obj.getCallsView().back());
			std::cout << std::endl;
		}
	}
};

}
}

#endif
