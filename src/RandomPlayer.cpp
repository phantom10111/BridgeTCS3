#include "RandomPlayer.hpp"

RandomPlayer::RandomPlayer()
{
	
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
}

Card RandomPlayer::getDummyCard()
{
	return getCard();
}

Call RandomPlayer::getCall()
{
}

Card RandomPlayer::getRandomCard()
{
}

Call RandomPlayer::getRandomCall()
{
}
