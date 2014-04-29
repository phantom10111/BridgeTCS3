#ifndef ARBITERCYCLE_HPP
#define ARBITERCYCLE_HPP

#include "model/Arbiter.hpp"

class ArbiterCycle{
private:
	int i;
	Arbiter data[4];
public:

	ArbiterCycle(IPlayer& a, IPlayer& b, IPlayer& c, IPlayer& d, std::vector<Call> const & callsView, std::vector<Trick> const & tricksView) : 
		data {
			Arbiter(a, callsView, tricksView),
			Arbiter(b, callsView, tricksView),
			Arbiter(c, callsView, tricksView),
			Arbiter(d, callsView, tricksView)
		}
	{
		i = 0;
	}
	
	Arbiter& next();
	void rotateTo(int);
	int getIndex();
	Arbiter& getAt(int);
};

#endif
