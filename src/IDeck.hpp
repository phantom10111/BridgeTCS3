#ifndef _DECK_H
#define _DECK_H
#include "Card.hpp"
class Deck{
	public:
		virtual Card& getCard()=0;
		virtual void shuffle()=0;
};
#endif
