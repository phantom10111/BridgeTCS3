#include "model/Deal.hpp"
#include "model/RandomDeck.hpp"

namespace model {

Deal::Deal(IPlayer &N, IPlayer &E, IPlayer &S, IPlayer &W) :
	phase(DealPhase::NOTSTARTED),
	arbiters(N, E, S, W, bidding.getCallsView(), play -> getTricksView())
{
	sigModified(*this);
}

DealResult Deal::perform() 
{
	phase = DealPhase::DEALING;
	sigModified(*this);
	dealCards();
	phase = DealPhase::BIDDING;
	sigModified(*this);
	doBidding();
	int res = 0;
	if(bidding.isSuccessful()){
		play = std::unique_ptr<Play>(new Play(bidding.getContract().denomination));
		phase = DealPhase::PLAYING;
		sigModified(*this);
		res = doPlay();
	}
	phase = DealPhase::FINISHED;
	sigModified(*this);
	return DealResult(bidding.getContract(), res);
}

DealPhase Deal::getCurrentPhase() const {
	return phase;
}

const Bidding & Deal::getBidding() const {
	return bidding;
}

const Play & Deal::getPlay() const {
	return *play;
}

const ArbiterCycle & Deal::getArbiters() const {
	return arbiters;
}

void Deal::dealCards() 
{
	RandomDeck<std::random_device> deck;
	deck.shuffle();
	arbiters.rotateTo(1);
	for(int i = 0; i < 13 * 4; ++i){
		arbiters.current().addCard(deck.getCard());
		arbiters.next();
	}
}

void Deal::doBidding() 
{
	arbiters.rotateTo(0);
	while(!bidding.hasEnded()){
		arbiters.current().makeCall(bidding);
		arbiters.next();
	}
}

int Deal::doPlay()
{
	const Contract contract = bidding.getContract();
	int dummy = (contract.player + 2) % 4;
	Arbiter::passDummyControl(arbiters.getAt(dummy), arbiters.getAt(contract.player));
	for(int i = 0; i < 4; ++i)
		if(i != dummy)
			arbiters.getAt(i).connectDummyView(arbiters.getAt(dummy));
	arbiters.rotateTo(contract.player);
	arbiters.next();
	while(!play->hasEnded())
	{
		for(int i = 0; i < 4; ++i)
		{
			if(arbiters.getIndex() == dummy)
				arbiters.getAt(contract.player).makeDummyMove(*play);
			else
				arbiters.current().makeMove(*play);
			arbiters.next();
		}
		arbiters.rotateTo((contract.player + play->getCurrentTrickStartingPlayer()) % 4);
	}
	return play->getTricksWon();
}

}
