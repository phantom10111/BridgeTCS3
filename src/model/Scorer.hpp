#ifndef SCORER_HPP
#define SCORER_HPP

#include "model/DealResult.hpp"

namespace model{

class Scorer{
public:
	bool update(DealResult const&);
	
	int getContractPoints(int); //team id
	
	int getOtherPoints(int); //team id
};
	
} // namespace model

#endif
