
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
	for(;;){
		Call call = player.getCall();
		if(bidding.canGetCall(call)){
			bidding.getCall(call);
			break;
		}
	}
}

bool Arbiter::checkMoveValidity(Play &play, Card &card)
{
	const std::vector<Trick> tricks = play.getTricksView(); 
	if (tricks.empty() || tricks.back().getCardsView().size() == 4) {
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
	for(;;){
		Card card = player.getCard();
		if(checkMoveValidity(play, card)){
			hand.removeCard(card);
			play.receiveCard(card);
			break;
		}
	}
}

void Arbiter::makeDummyMove(Play &play) 
{
	throw "Not yet implemented";
}

void Arbiter::passDummyControl(Arbiter &from, Arbiter &to)
{
	to.player.connectDummyHand(from.hand.getCardsView());
}
