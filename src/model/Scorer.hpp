#ifndef SCORER_HPP
#define SCORER_HPP

#include "model/DealResult.hpp"

namespace model{

class Scorer{
public:
	bool update(DealResult const&);
};
	
} // namespace model

#endif
