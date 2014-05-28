#ifndef RANDOMPLAYER_HPP
#define RANDOMPLAYER_HPP

#include <vector>
#include <random>
#include <utility>
#include "model/IPlayer.hpp"
#include "model/Card.hpp"
#include "model/Call.hpp"
#include "model/Denomination.hpp"
#include "model/Play.hpp"

namespace model {

template<typename URNG>
class RandomPlayer : public IPlayer
{
public:
	RandomPlayer(RandomPlayer&) = delete;
	RandomPlayer(RandomPlayer&&) = delete;

	template<typename... Args>
	RandomPlayer(Args... args) :
		suitDistribution(0,3),
		rankDistribution(0,12),
		callTypeDistribution(0,3),
		levelDistribution(1,7),
		denominationDistribution(0,4),
		generator(std::forward<Args>(args)...)
	{
	}

	void connectGameState(const std::vector<Card>& cardsView, const std::vector<Call>& callsView, const Play::Tricks & tricksView)
	{
		return;
	}

	void connectDummyHand(const std::vector<Card>& cardsView)
	{
		return;
	}

	Card getCard()
	{
		return getRandomCard();
	}

	Card getDummyCard()
	{
		return getRandomCard();
	}

	Call getCall()
	{
		return getRandomCall();
	}

private:
	std::uniform_int_distribution<> suitDistribution;
	std::uniform_int_distribution<> rankDistribution;
	std::uniform_int_distribution<> callTypeDistribution;
	std::uniform_int_distribution<> levelDistribution;
	std::uniform_int_distribution<> denominationDistribution;
	URNG generator;

	Card getRandomCard()
	{
		return Card(getRandomSuit(), getRandomRank());
	}

	Suit getRandomSuit()
	{
		return static_cast<Suit>(suitDistribution(generator));
	}

	Rank getRandomRank()
	{
		return static_cast<Rank>(rankDistribution(generator));
	}

	Call getRandomCall()
	{
		CallType callType = getRandomCallType();
		switch(callType)
		{
			case CallType::PASS:
				return Call::PASS();
			case CallType::DOUBLE:
				return Call::DOUBLE();
			case CallType::REDOUBLE:
				return Call::REDOUBLE();
			case CallType::BID:
				return Call::BID(getRandomLevel(), getRandomDenomination());
		}
	}

	CallType getRandomCallType()
	{
		return static_cast<CallType>(callTypeDistribution(generator));
	}

	int getRandomLevel()
	{
		return levelDistribution(generator);
	}

	Denomination getRandomDenomination()
	{
		return static_cast<Denomination>(denominationDistribution(generator));
	}
};

}

#endif
