#ifndef DEAL_HPP
#define DEAL_HPP

#include "model/Arbiter.hpp"
#include "model/ArbiterCycle.hpp"
#include "model/Bidding.hpp"
#include "model/DealResult.hpp"
#include "model/IPlayer.hpp"
#include "model/Play.hpp"
#include "model/DealResult.hpp"
#include "model/ArbiterCycle.hpp"
#include "ui/IObservable.hpp"

namespace model {

enum class DealPhase {
	NOTSTARTED,
	DEALING,
	BIDDING,
	PLAYING,
	FINISHED
};

class Deal : public ui::IObservable<Deal> {
public:
	Deal(IPlayer&, IPlayer &, IPlayer &, IPlayer &);
	DealResult perform();
	DealPhase getCurrentPhase();
	const Bidding & getBidding();
	const ArbiterCycle & getArbiters();
private:
	DealPhase phase;
	Bidding bidding;
	Play play;
	ArbiterCycle arbiters;
	void dealCards();
	void doBidding();
	int doPlay();
};

}

#endif
