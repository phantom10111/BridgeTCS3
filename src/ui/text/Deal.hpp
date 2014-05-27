#ifndef UI_TEXT_DEAL_HPP
#define UI_TEXT_DEAL_HPP

#include <iostream>

#include "model/Deal.hpp"
#include "model/Bidding.hpp"
#include "model/ArbiterCycle.hpp"
#include "ui/text/Bidding.hpp"
#include "ui/text/ArbiterCycle.hpp"

namespace ui {
namespace text {

class Deal
{
private:
	model::DealPhase phase;
	ArbiterCycle arbitersView;
	Bidding biddingView;
public:
	Deal() :
		phase(model::DealPhase::NOTSTARTED),
		biddingView(arbitersView.getActivePlayerView())
	{
	}
	void notify(const model::Deal& obj) {
		if(obj.getCurrentPhase() != phase){
			if(phase == model::DealPhase::NOTSTARTED){
				obj.getArbiters().sigModified.connect(
					[this](model::ArbiterCycle const & arbiters){arbitersView.notify(arbiters);}
				);
				obj.getBidding().sigModified.connect(
					[this](model::Bidding const & bidding){biddingView.notify(bidding);}
				);
			}
			phase = obj.getCurrentPhase();
		}
	}
};

}
}

#endif
