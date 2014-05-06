#include "model/Play.hpp"

namespace model {

Play::Play()
{
	tricksWon = 0;
	currentStarting = 1;
}

void Play::setTrump(Denomination denomination)
{
	trump = denomination;
}

const std::vector<Trick>& Play::getTricksView()
{
	return tricks;
}

void Play::receiveCard(Card card)
{
	if(tricks.empty() || tricks.back().hasEnded())
		tricks.emplace_back(trump);
	tricks.back().addCard(card);
	if(tricks.back().hasEnded())
	{
		currentStarting = (currentStarting + tricks.back().getWinner()) % 4;
		if(currentStarting % 2 == 0)
			tricksWon++;
	}
}

Suit Play::getLeadingSuit()
{
	return tricks.back().getCardsView()[0].suit;
}

int Play::getCurrentTrickStartingPlayer()
{
	return currentStarting;
}

bool Play::hasEnded()
{
	return tricks.size() == 13 && tricks.back().hasEnded();
}

int Play::getTricksWon()
{
	return tricksWon;
}

}