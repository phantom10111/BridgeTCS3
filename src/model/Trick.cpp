#include "Trick.hpp"
Trick::Trick(Denomination trump) : trump(trump)
{
	
}

void Trick::addCard(Card card)
{
	cards.push_back(card);
}

int Trick::getWinner() const
{
	int winner = 0;
	int playerIdx = 0;
	for(Card const & card: cards){
		if(compareCards(cards[winner], card))
			winner = playerIdx;
		playerIdx++;
	}
	return winner;
}

std::vector<Card> const & Trick::getCardsView() const
{
	return cards;
}

bool Trick::hasEnded() const
{
	return cards.size() == 4;
}

bool Trick::compareCards(Card const & card1, Card const & card2) const{
	if(isTrump(card1.suit))
		return (isTrump(card2.suit) && card1.rank < card2.rank);
	return isTrump(card2.suit) || 
		(card2.suit == card1.suit && card1.rank < card2.rank);
}

bool Trick::isTrump(Suit suit) const{
	return static_cast<Denomination>(suit) == trump;
}
