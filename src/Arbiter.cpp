
#include "Arbiter.hpp"

Arbiter::Arbiter(IPlayer& player,
	std::vector<Call> const & callsView,
	std::vector<Trick> const & tricksView) :
	player(player), callsView(callsView), tricksView(tricksView)
{
	player.connectGameState(hand.getCardsView(), callsView, tricksView);
}

void Arbiter::addCard(Card c)
{
	hand.addCard(c);
}

void Arbiter::makeCall(Bidding &bidding)
{
	bool success = false;
	Call call;
	while (!success) {
		call = player.getCall();
		success = bidding.canGetCall(call);
	}
	bidding.getCall(call);
}

bool Arbiter::checkMoveValidity(Play &play, Card &card) {
	const std::vector<Trick> tricks =  play.getTricksView(); 
	if (tricks.empty() || tricks.back().getCardsView.size() == 4) {
		return true;
	} 
	const std::vector<Card> cards = tricks.back().getCardsView();
	Card firstCard = cards.front();
	if (hand.hasSuit(firstCard.suit) && firstCard.suit != card.suit) {
		return false;
	}
	return true;
}
	

void Arbiter::makeMove(Play &play) 
{
	bool success = false;
	Card card;
	while (!success) {
		card = player.getCard();
		success = checkMoveValidity(play, card);
	}
	hand.removeCard(card);
	play.receiveCard(card);
}

