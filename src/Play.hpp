#ifndef PLAY_HPP
#define PLAY_HPP

#include <vector>
#include "Denomination.hpp"
#include "Card.hpp"
#include "Trick.hpp"

class Play
{
public:
	Play(Denomination);
	const std::vector<Trick> & getTricksView(); 
	void receiveCard(Card);
	Suit getLeadingSuit();
	int getCurrentTrickStartingPlayer();
	bool hasEnded();
	int getTricksWon();
};

#endif
