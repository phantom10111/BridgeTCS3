#ifndef DEALRESULT_HPP
#define DEALRESULT_HPP

#include "model/Contract.hpp"

namespace model {

struct DealResult {
	bool successful;
	Contract contract;
	int tricksWon;

	DealResult(Contract, int tricksWon) :
		successful(true),
		contract(contract),
		tricksWon(tricksWon)
	{
	}
};

} // namespace model

#endif
