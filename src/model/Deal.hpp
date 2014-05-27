#ifndef DEAL_HPP
#define DEAL_HPP

#include <memory>
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
	Deal(Deal&) = delete;
	Deal(Deal&&) = delete;
	Deal(IPlayer&, IPlayer &, IPlayer &, IPlayer &);
	DealResult perform();
	DealPhase getCurrentPhase() const;
	const Bidding & getBidding() const;
	const Play & getPlay() const;
	const ArbiterCycle & getArbiters() const;
private:
	DealPhase phase;
	Bidding bidding;
	std::unique_ptr<Play> play;
	ArbiterCycle arbiters;
	void dealCards();
	void doBidding();
	int doPlay();
};

}

#endif
