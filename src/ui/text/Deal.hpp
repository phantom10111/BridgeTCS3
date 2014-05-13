#ifndef UI_TEXT_DEAL_HPP
#define UI_TEXT_DEAL_HPP

#include <iostream>

#include "model/Deal.hpp"
#include "ui/text/Bidding.hpp"

namespace ui {
namespace text {

class Deal
{
private:
	DealPhase phase;
	Bidding biddingView;
public:
	Deal() :
		phase(NOTSTARTED) 
	{
	}
	void notify(const model::Deal& obj) {
		if(obj.getCurrentPhase() != phase){
			phase = obj.getCurrentPhase();
			if(phase == BIDDING){
				obj.getBidding().sigModified.connect(
					[&biddingView](model::Bidding const & bidding){biddingView.notify(bidding);}
				);
			}
		}
	}
};

}
}

#endif
