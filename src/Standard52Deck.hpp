#ifndef _STANDARD52DECK_H
#define _STANDARD52DECK_H
#include "Card.hpp"
#include "Deck.hpp"
#include <vector>
class Standard52Deck: public Deck{
	public:
		Standard52Deck();
		Card& getCard();
		void shuffle();
	private:
		std::vector<Card>& cards;
};
#endif
