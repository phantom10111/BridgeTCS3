#ifndef DEALRESULT_HPP
#define DEALRESULT_HPP

#include "model/Contract.hpp"

namespace model {

struct DealResult {
	Contract contract;
	int tricksWon;

	DealResult(Contract contract, int tricksWon) :
		contract(contract),
		tricksWon(tricksWon)
	{
	}
};

} // namespace model

#endif
