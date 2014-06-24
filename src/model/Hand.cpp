#include <stdexcept>
#include "model/Hand.hpp"

#include <iostream>
#include <stdexcept>

namespace model {

std::vector<Card> const & Hand::getCardsView() const 
{
	return cards;
}

void Hand::addCard(Card c) 
{
	cards.push_back(c);
	sigModified(*this);
}

void Hand::removeCard(Card c) 
{
	for (std::vector<Card>::iterator it = cards.begin(); it != cards.end(); it++) {
		if ((*it).suit == c.suit && (*it).rank == c.rank) {
			cards.erase(it);
			sigModified(*this);
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

bool Hand::hasCard(Card card) {
	for(Card c : cards) {
		if(card == c)
			return true;
	}
	return false;
}

int Hand::getHonorBonus(Denomination den) const
{
	if(cards.size()!=(52/4))
		throw std::runtime_error("Not all cards in hand");
	if(den == Denomination::NO_TRUMP){
		int acesNr=0;
		for(Card c: cards){
			if(c.rank==Rank::ACE){
				++acesNr;
			}
		}
		if(acesNr==4){
			return 150;
		}
	}
	else{
		int honorCount=0;
		for(Card c: cards){
			if(((int) c.suit == (int) den) && (c.rank==Rank::TEN 
				|| c.rank==Rank::JACK || c.rank==Rank::QUEEN 
				|| c.rank==Rank::KING || c.rank==Rank::ACE)){
					++honorCount;
			}
		}
		if(honorCount==4){
			return 100;
		}
		else if(honorCount==5){
			return 150;
		}
		else{
			return 0;
		}
	}
}

}
