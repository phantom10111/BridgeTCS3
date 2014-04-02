#ifndef BIDDING_HPP
#define BIDDING_HPP

#include "Call.hpp"
#include "Contract.hpp"

#include <vector>

class Bidding
{
	private:
	bool ended;
	bool successful;
	Call const * lastCall;
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

#endif

