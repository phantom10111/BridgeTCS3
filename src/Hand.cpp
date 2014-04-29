#include <stdexcept>
#include "Hand.hpp"

#include <iostream>

std::vector<Card> const & Hand::getCardsView() const 
{
	return cards;
}

void Hand::addCard(Card c) 
{
//	std::cout << "dostaje karte, a mialem " << cards.size() << std::endl;
	cards.push_back(c);
}

void Hand::removeCard(Card c) 
{
	for (std::vector<Card>::iterator it = cards.begin(); it != cards.end(); it++) {
		if ((*it).suit == c.suit && (*it).rank == c.rank) {
			cards.erase(it);
			return;
		}
	}
	throw std::invalid_argument("No such card in hand!");
}

bool Hand::hasSuit(Suit suit) {
	for (auto c: cards) {
		if (c.suit == suit) return true;
	}
	return false;
}
