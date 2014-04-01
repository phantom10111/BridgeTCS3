
#include "Arbiter.hpp"

Arbiter::Arbiter(IPlayer& player,
	std::vector<Call> const & callsView,
	std::vector<Trick> const & tricksView){
	player.connectGameState(cards, callsView, tricksView);
}

void Arbiter::addCard(Card c){
}
