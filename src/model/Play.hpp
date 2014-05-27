#ifndef PLAY_HPP
#define PLAY_HPP

#include <list>
#include "model/Denomination.hpp"
#include "model/Card.hpp"
#include "model/Trick.hpp"


namespace model {

class Play
{
public:
	Play(Play&) = delete;
	Play(Play&&) = delete;
	using Tricks = std::list<Trick>;
	Play(Denomination);
	const Tricks & getTricksView(); 
	void receiveCard(Card);
	Suit getLeadingSuit();
	int getCurrentTrickStartingPlayer();
	bool hasEnded();
	int getTricksWon();

private:
	Denomination trump;
	int currentStarting;
	Tricks tricks;
	int tricksWon;
};

}

#endif
