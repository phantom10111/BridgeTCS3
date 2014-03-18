#ifndef _STANDARD52DECK_H
#define _STANDARD52DECK_H
#include "Card.hpp"
#include "Deck.hpp"
class Standard52Deck: public Deck{
	public:
		Card getCard();
		void shuffle();
	private:
		vector<Card> cards;
};
#endif
