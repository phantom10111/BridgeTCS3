#ifndef SCORER_HPP
#define SCORER_HPP

#include "model/DealResult.hpp"
#include "model/GameResult.hpp"

namespace model{

class Scorer{
public:
	bool update(DealResult const&);
	GameResult getResult() const;
};
	
} // namespace model

#endif
