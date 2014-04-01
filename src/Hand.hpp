#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"

class Hand {
private:
	std::vector<Card> cards;
public:
	std::vector<Call> const &getCardsView() const;
	void addCard(Card c);
	void removeCard(Card c);
};

#endif
