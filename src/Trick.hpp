#ifndef TRICK_HPP
#define TRICK_HPP
#include "Card.hpp"
#include "Denomination.hpp"
#include<vector>
class Trick
{
public:
	Trick(Denomination);
	void addCard(Card);
	int getWinner() const;
	std::vector<Card> const & getCardsView() const;
private:
	bool compareCards(Card const & card1, Card const & card2) const; // (card 1 < card 2)
	bool isTrump(Suit suit) const;
	Denomination trump;
	std::vector<Card> cards;
};
#endif
