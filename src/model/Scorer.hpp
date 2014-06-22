#ifndef SCORER_HPP
#define SCORER_HPP

#include <array>
#include "model/DealResult.hpp"
#include "model/GameResult.hpp"

namespace model{

class Scorer{
public:
	Scorer();
	bool isVulnerable(int nr);
	bool update(DealResult const&);
	GameResult getResult() const;
private:
	GameResult gameResult;
	int gamesWon[2];
};
	
} // namespace model

#endif
