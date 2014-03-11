#ifndef _BIDDING_HPP_
#define _BIDDING_HPP_

#include "Call.hpp"
#include "Contract.hpp"

class Bidding
{
	public:
	bool getCall(const Call);
	bool hasEnded() const;
	Contract getContract() const;
};

#endif
