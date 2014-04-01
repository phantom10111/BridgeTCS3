#ifndef ARBITER_HPP
#define ARBITER_HPP

#include "Card.hpp"
#include "Call.hpp"
#include "Trick.hpp"
#include "IPlayer.hpp"

class Arbiter {
public:
	Arbiter(IPlayer& player,
		std::vector<Call> const & callsView,
		std::vector<Trick> const & tricksView);
	void addCard(Card c);
	Card getCard();
	Call makeCall();
};

#endif
