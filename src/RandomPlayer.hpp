#ifndef RANDOMPLAYER_HPP
#define RANDOMPLAYER_HPP

#include <vector>
#include <random>
#include "IPlayer.hpp"

class RandomPlayer : public IPlayer
{
public:
	RandomPlayer();
	void connectGameState(const std::vector<Card>& cardsView, const std::vector<Call>& callsView, const std::vector<Trick>& tricksView);
	void connectDummyHand(const std::vector<Card>& cardsView);
	Card getCard();
	Card getDummyCard();
	Call getCall();

private:
	Card getRandomCard();
	Call getRandomCall();
};

#endif
