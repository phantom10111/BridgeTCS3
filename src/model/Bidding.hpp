#ifndef BIDDING_HPP
#define BIDDING_HPP

#include "model/Call.hpp"
#include "model/Contract.hpp"
#include "ui/IObservable.hpp"

#include <vector>

namespace model {

class Bidding : public ui::IObservable<Bidding>
{
	private:
	bool ended;
	bool successful;
	Call lastCall;
	int multiplier;
	int lastPlayer;
	int numPasses;
	int lastCallPlayer;
	int lastColorCallPlayer[5][2];
	std::vector<Call> calls;

	public:
	Bidding();
	bool canGetCall(Call const &) const;
	void getCall(Call const &);
	std::vector<Call> const &getCallsView() const;
	bool hasEnded() const;
	bool isSuccessful() const;
	Contract getContract() const;
};

}

#endif

