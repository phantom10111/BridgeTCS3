
#include "Arbiter.hpp"

Arbiter::Arbiter(IPlayer& player,
	std::vector<Call> const & callsView,
	std::vector<Trick> const & tricksView)
{
	player.connectGameState(hand.getCardsView(), callsView, tricksView);
}

void Arbiter::addCard(Card c)
{
	hand.addCard(c);
}
