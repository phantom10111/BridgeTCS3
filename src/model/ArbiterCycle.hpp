#ifndef ARBITERCYCLE_HPP
#define ARBITERCYCLE_HPP

#include <array>
#include "model/Arbiter.hpp"
#include "model/Play.hpp"

namespace model {

class ArbiterCycle : public ui::IObservable<ArbiterCycle> {
private:
	int i;
	std::array<Arbiter, 4> data;
public:
	ArbiterCycle(ArbiterCycle&) = delete;
	ArbiterCycle(ArbiterCycle&&) = delete;
	ArbiterCycle(IPlayer& a, IPlayer& b, IPlayer& c, IPlayer& d, std::vector<Call> const & callsView, Play::Tricks const & tricksView) : 
		i(0),
		data {{
			{a, callsView, tricksView},
			{b, callsView, tricksView},
			{c, callsView, tricksView},
			{d, callsView, tricksView}
		}}
	{}
	
	void next();
	Arbiter& current();
	void rotateTo(int);
	int getIndex() const;
	Arbiter& getAt(int);
};

}

#endif
