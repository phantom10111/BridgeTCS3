#ifndef __ARBITER_HPP
#define __ARBITER_HPP

#include "Card.hpp"
#include "Call.hpp"

class Arbiter {
public:
	Arbiter(const Player& player, const Trick& lastTrick);
	void addCard(Card c);
	Card getCard();
	Call makeCall();
}

#endif
