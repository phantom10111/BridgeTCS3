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
	Play::Tricks const & tricksView;
	
	bool checkMoveValidity(Play&, Card&, Hand&);
	
public:
	Arbiter(Arbiter&) = delete;
	Arbiter(Arbiter&&) = delete;
	Arbiter(IPlayer& player,
		std::vector<Call> const & callsView,
		Play::Tricks const & tricksView);
	void addCard(Card c);
	void makeMove(Play &play);
	void makeDummyMove(Play &play);
	void makeCall(Bidding &bidding);
	int getHonorBonus(Denomination den) const;
	static void passDummyControl(Arbiter &from, Arbiter &to);
	void connectDummyView(Arbiter &from);
};

}

#endif
