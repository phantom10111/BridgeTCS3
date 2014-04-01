#include "Play.hpp"

Play::Play(Denomination denomination)
{
}

const std::vector<Trick>& Play::getTricksView()
{
	throw "not yet implemented";
}

void Play::receiveCard(Card card)
{
	throw "not yet implemented";
}

Suit Play::getLeadingSuit()
{
	throw "not yet implemented";
}

int Play::getCurrentTrickStartingPlayer()
{
	throw "not yet implemented";
}

bool Play::hasEnded()
{
	throw "not yet implemented";
}

int Play::getTricksWon()
{
	throw "not yet implemented";
}
