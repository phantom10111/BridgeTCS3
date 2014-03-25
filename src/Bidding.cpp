#include "Bidding.hpp"
#include "Call.hpp"
#include "Contract.hpp"

#include <vector>
#include <stdexcept>

Bidding::Bidding() :
	ended(false),
	lastCall(Call::PASS()),
	multiplier(1),
	lastPlayer(-1),
	numPasses(-1),
	lastCallPlayer(-1)
{ }

bool Bidding::canGetCall(Call const &call) const
{
	return true;
}

void Bidding::getCall(Call const &call)
{
	if(!canGetCall(call))
		throw std::runtime_error("Incorrect call");
	calls.push_back(call);
}

std::vector<Call> const &Bidding::getCallsView() const
{
	return calls;
}

bool Bidding::hasEnded() const
{
	return ended;
}

bool Bidding::isSuccessful() const
{
	if(!ended)
		throw std::runtime_error("Bidding not finished");
	return successful;
}

Contract Bidding::getContract() const
{
	if(!ended)
		throw std::runtime_error("Bidding not finished");
	if(!successful)
		throw std::runtime_error("Bidding not successful");
	return Contract(lastCall.level, lastCall.denomination, multiplier, 0);
}
