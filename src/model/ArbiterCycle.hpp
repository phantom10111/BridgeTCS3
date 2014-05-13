#ifndef ARBITERCYCLE_HPP
#define ARBITERCYCLE_HPP

#include "model/Arbiter.hpp"

namespace model {

class ArbiterCycle{
private:
	int i;
	std::array<Arbiter, 4> data;
public:

	ArbiterCycle(IPlayer& a, IPlayer& b, IPlayer& c, IPlayer& d, std::vector<Call> const & callsView, std::vector<Trick> const & tricksView) : 
		i(0),
		data {{
			{a, callsView, tricksView},
			{b, callsView, tricksView},
			{c, callsView, tricksView},
			{d, callsView, tricksView}
		}}
	{}
	
	Arbiter& next();
	void rotateTo(int);
	int getIndex();
	Arbiter& getAt(int);
};

}

#endif
