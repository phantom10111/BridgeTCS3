#ifndef PLAY_HPP
#define PLAY_HPP

#include <list>
#include "model/Denomination.hpp"
#include "model/Card.hpp"
#include "model/Trick.hpp"
#include "ui/IObservable.hpp"

namespace model {

class Play : public ui::IObservable<Play>
{
public:
	Play(Play&) = delete;
	Play(Play&&) = delete;
	using Tricks = std::list<Trick>;
	Play(Denomination);
	const Tricks & getTricksView() const;
	void receiveCard(Card);
	Suit getLeadingSuit() const;
	int getCurrentTrickStartingPlayer() const;
	bool hasEnded() const;
	int getTricksWon() const;

private:
	Denomination trump;
	int currentStarting;
	Tricks tricks;
	int tricksWon;
};

}

#endif
