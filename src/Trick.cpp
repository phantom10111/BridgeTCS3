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

bool Trick::compareCards(Card const & card1, Card const & card2){
	if(isTrump(card1.suit))
		return (isTrump(card2.suit) && card1.rank < card2.rank);
	return isTrump(card2.suit) || 
		(card2.suit == card1.suit && card1.rank < card2.rank);
}
bool Trick::isTrump(Suit suit){
	return static_cast<Denomination>(suit) == trump;
}
