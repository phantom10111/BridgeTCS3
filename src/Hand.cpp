#include <stdexcept>
#include "Hand.hpp"


std::vector<Call> const & Hand::getCardsView() const 
{
	return cards;
}

void Hand::addCard(Card c) 
{
	cards.push_back(c);
}

void removeCard(Card c) 
{
	for (std::vector<Card>::iterator it = cards.begin(); it != cards.end(); it++) {
		if ((*it).suit == c.suit && (*it).rank == c.rank) {
			cards.erase(it);
			return;
		}
	}
	throw std::invalid_argument("No such card in hand!");
}
