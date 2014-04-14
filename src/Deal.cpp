
#include "Deal.hpp"
#include "BridgeDeck.hpp"

Deal::Deal(IPlayer &N, IPlayer &E, IPlayer &S, IPlayer &W) :
	N(N, bidding.getCallsView(), play.getTricksView()),
	E(E, bidding.getCallsView(), play.getTricksView()),
	S(S, bidding.getCallsView(), play.getTricksView()),
	W(W, bidding.getCallsView(), play.getTricksView())
{
}

Result Deal::perform() 
{
	dealCards();
}

void Deal::dealCards() 
{
	BridgeDeck deck;
	deck.shuffle();
	for(int i = 0; i < 13; ++i){
		N.addCard(deck.getCard());
		E.addCard(deck.getCard());
		S.addCard(deck.getCard());
		W.addCard(deck.getCard());
	}
}
