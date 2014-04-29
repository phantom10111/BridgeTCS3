#ifndef ARBITER_HPP
#define ARBITER_HPP

#include "model/Bidding.hpp"
#include "model/Card.hpp"
#include "model/Call.hpp"
#include "model/Hand.hpp"
#include "model/Play.hpp"
#include "model/Trick.hpp"
#include "model/IPlayer.hpp"

namespace model {

class Arbiter {
private:
	Hand hand;
	Hand * dummyHand;
	IPlayer& player;
	std::vector<Call> const & callsView;
	std::vector<Trick> const & tricksView;
	
	bool checkMoveValidity(Play&, Card&, Hand&);
	
public:
	Arbiter(IPlayer& player,
		std::vector<Call> const & callsView,
		std::vector<Trick> const & tricksView);
	void addCard(Card c);
	void makeMove(Play &play);
	void makeDummyMove(Play &play);
	void makeCall(Bidding &bidding);
	static void passDummyControl(Arbiter &from, Arbiter &to);
};

}

#endif
