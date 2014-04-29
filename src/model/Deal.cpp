
#include "model/Deal.hpp"
#include "model/BridgeDeck.hpp"

Deal::Deal(IPlayer &N, IPlayer &E, IPlayer &S, IPlayer &W) :
	arbiters(N, E, S, W, bidding.getCallsView(), play.getTricksView())
{
}

Result Deal::perform() 
{
	dealCards();
	doBidding();
	if(bidding.isSuccessful())
		doPlay();
	return Result();
}

void Deal::dealCards() 
{
	BridgeDeck deck;
	deck.shuffle();
	arbiters.next();
	for(int i = 0; i < 13 * 4; ++i)
		arbiters.next().addCard(deck.getCard());
}

void Deal::doBidding() 
{
	arbiters.rotateTo(0);
	while(!bidding.hasEnded())
		arbiters.next().makeCall(bidding);
}

void Deal::doPlay() 
{
	const Contract contract = bidding.getContract();
	arbiters.rotateTo(contract.player);
	int dummy = (contract.player + 2) % 4;
	Arbiter::passDummyControl(arbiters.getAt(dummy), arbiters.getAt(contract.player));
	arbiters.next();
	play.setTrump(contract.denomination);
	while(!play.hasEnded()){
		for(int i = 0; i < 4; ++i)
			if(arbiters.getIndex() == dummy)
				arbiters.getAt(contract.player).makeDummyMove(play);
			else
				arbiters.next().makeMove(play);
		arbiters.rotateTo((contract.player + play.getCurrentTrickStartingPlayer()) % 4);
	}
}
