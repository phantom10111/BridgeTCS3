
#include "Arbiter.hpp"

Arbiter::Arbiter(IPlayer& player,
	std::vector<Call> const & callsView,
	std::vector<Trick> const & tricksView){
	std::vector<Card> cards;
	player.connectGameState(cards, callsView, tricksView);
}

