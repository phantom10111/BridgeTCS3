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
public:
	Bidding() : callsCount(0) {}
	void notify(const model::Bidding& obj) {
		if(obj.getCallsView().size() != callsCount){
			callsCount = obj.getCallsView().size();
			Printer::print(obj.getCallsView().back());
			std::cout << std::endl;
		}
	}
};

}
}

#endif
