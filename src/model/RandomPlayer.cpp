#include "model/RandomPlayer.hpp"

RandomPlayer::RandomPlayer(int seed)
{
	suitDistribution = std::uniform_int_distribution<>(0,3);
	rankDistribution = std::uniform_int_distribution<>(0,12);
	callTypeDistribution = std::uniform_int_distribution<>(0,3);
	levelDistribution = std::uniform_int_distribution<>(1,7);
	denominationDistribution = std::uniform_int_distribution<>(0,4);
	generator = std::mt19937(seed);
}

void RandomPlayer::connectGameState(const std::vector<Card>& cardsView, const std::vector<Call>& callsView, const std::vector<Trick>& tricksView)
{
	return;
}

void RandomPlayer::connectDummyHand(const std::vector<Card>& cardsView)
{
	return;
}

Card RandomPlayer::getCard()
{
	return getRandomCard();
}

Card RandomPlayer::getDummyCard()
{
	return getRandomCard();
}

Call RandomPlayer::getCall()
{
	return getRandomCall();
}

Card RandomPlayer::getRandomCard()
{
	return Card(getRandomSuit(), getRandomRank());
}

Suit RandomPlayer::getRandomSuit()
{
	return static_cast<Suit>(suitDistribution(generator));
}

Rank RandomPlayer::getRandomRank()
{
	return static_cast<Rank>(rankDistribution(generator));
}

Call RandomPlayer::getRandomCall()
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

CallType RandomPlayer::getRandomCallType()
{
	return static_cast<CallType>(callTypeDistribution(generator));
}

int RandomPlayer::getRandomLevel()
{
	return levelDistribution(generator);
}

Denomination RandomPlayer::getRandomDenomination()
{
	return static_cast<Denomination>(denominationDistribution(generator));
}
