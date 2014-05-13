#ifndef UI_TEXT_DEAL_HPP
#define UI_TEXT_DEAL_HPP

#include <iostream>

#include "model/Deal.hpp"
#include "model/Bidding.hpp"
#include "model/ArbiterCycle.hpp"
#include "ui/text/Bidding.hpp"

namespace ui {
namespace text {

class Deal
{
private:
	DealPhase phase;
	Bidding biddingView;
	ArbiterCycle arbitersView;
public:
	Deal() :
		phase(NOTSTARTED) 
	{
	}
	void notify(const model::Deal& obj) {
		if(obj.getCurrentPhase() != phase){
			if(phase == NOTSTARTED){
				obj.getArbiters().sigModified.connect(
					[&arbitersView](model::ArbiterCycle const & arbiters){arbitersView.notify(arbiters);}
				);
				obj.getBidding().sigModified.connect(
					[&biddingView](model::Bidding const & bidding){biddingView.notify(bidding);}
				);
			}
			phase = obj.getCurrentPhase();
		}
	}
};

}
}

#endif
