#ifndef DEALRESULT_HPP
#define DEALRESULT_HPP

#include <array>
#include "model/Contract.hpp"


namespace model {

struct DealResult {
	Contract contract;
	int tricksWon;
	std::array<int, 2> honorBonus;

	DealResult(Contract contract, int tricksWon, int team0Bonus, int team1Bonus) :
		contract(contract),
		tricksWon(tricksWon)
	{
		honorBonus[0]=team0Bonus;
		honorBonus[1]=team1Bonus;
	}
};

} // namespace model

#endif
