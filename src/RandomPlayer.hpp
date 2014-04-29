#ifndef RANDOMPLAYER_HPP
#define RANDOMPLAYER_HPP

#include <vector>
#include <random>
#include "IPlayer.hpp"
#include "Card.hpp"
#include "Call.hpp"
#include "Denomination.hpp"

class RandomPlayer : public IPlayer
{
public:
	RandomPlayer(int seed);
	void connectGameState(const std::vector<Card>& cardsView, const std::vector<Call>& callsView, const std::vector<Trick>& tricksView);
	void connectDummyHand(const std::vector<Card>& cardsView);
	Card getCard();
	Card getDummyCard();
	Call getCall();

private:
	std::uniform_int_distribution<> suitDistribution;
	std::uniform_int_distribution<> rankDistribution;
	std::uniform_int_distribution<> callTypeDistribution;
	std::uniform_int_distribution<> levelDistribution;
	std::uniform_int_distribution<> denominationDistribution;
	std::mt19937 generator;
	Card getRandomCard();
	Suit getRandomSuit();
	Rank getRandomRank();
	Call getRandomCall();
	CallType getRandomCallType();
	int getRandomLevel();
	Denomination getRandomDenomination();
};

#endif
