#include "Bidding.hpp"
#include "Call.hpp"
#include "Contract.hpp"

#include <vector>
#include <stdexcept>

Bidding::Bidding() :
	ended(false),
	successful(false),
	lastCall(Call::PASS()),
	multiplier(1),
	lastPlayer(-1),
	numPasses(-1),
	lastCallPlayer(-1)
{
	for(int i=0;i<5;i++){
		for(int j=0;j<2;j++){
			lastColorCallPlayer[i][j] = -1;
		}
	}
}

bool Bidding::canGetCall(Call const &call) const
{
	if(ended)
		throw std::runtime_error("Bidding has already ended");
	switch(call.type)
	{
		case CallType::DOUBLE:
		
			if(multiplier != 1)
			{
				return false;
			}
			if(lastPlayer == -1 || lastCallPlayer == -1 || ((lastPlayer+1)%2 == lastCallPlayer%2))
			{
				return false;
			}
			break;
		
		case CallType::REDOUBLE:

			if(multiplier != 2)
			{
				return false;
			}
			if(lastPlayer == -1 || lastCallPlayer == -1 || ((lastPlayer+1)%2 != lastCallPlayer%2))
			{
				return false;
			}
			break;
		
		case CallType::BID:
		
			if(numPasses >= 0 && lastCall.type != Call::PASS().type)
			{
				if(call.level < lastCall.level)
				{
					return false;
				}
				if(call.level > lastCall.level)
				{
					return true;
				}
				if(call.denomination <= lastCall.denomination)
				{
					return false;
				}
			}
		
		case CallType::PASS:
		
		return true;
	}		
	return true;
}

void Bidding::getCall(Call const &call)
{
	if(!canGetCall(call))
		throw std::runtime_error("Incorrect call");
	calls.push_back(call);
	if(numPasses == -1 && call.type == CallType::BID)
		numPasses = 0;
	lastPlayer = (lastPlayer+1)%4;
	if(call.type == CallType::PASS)
	{
		numPasses++;
		if(numPasses == 3)
		{
			ended = true;
			if(lastCallPlayer == -1)
			{
				successful = false;
			}else{
				successful = true;
			}
			return;
		}
	} else
	{
		numPasses = 0;
	}
	if(call.type == CallType::DOUBLE || call.type == CallType::REDOUBLE)
	{
		multiplier *= 2;
	} else if(call.type == CallType::BID)
	{
		multiplier = 1;
		lastPlayer = lastPlayer;
		lastCall = call;
		lastCallPlayer = lastPlayer;
		if(lastColorCallPlayer[(int)call.denomination][lastPlayer%2] == -1)
		{
			lastColorCallPlayer[(int)call.denomination][lastPlayer%2] = lastPlayer;
		}
	}
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
	return Contract(lastCall.level, lastCall.denomination, multiplier, lastColorCallPlayer[(int)lastCall.denomination][lastCallPlayer%2]);
}
