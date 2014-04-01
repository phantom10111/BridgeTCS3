#ifndef ARBITER_HPP
#define ARBITER_HPP

#include "Bidding.hpp"
#include "Card.hpp"
#include "Call.hpp"
#include "Hand.hpp"
#include "Play.hpp"
#include "Trick.hpp"
#include "IPlayer.hpp"

class Arbiter {
private:
	Hand hand;
public:
	Arbiter(IPlayer& player,
		std::vector<Call> const & callsView,
		std::vector<Trick> const & tricksView);
	void addCard(Card c);
	void makeMove(Play &play);
	void makeCall(Bidding &bidding);
};

#endif
