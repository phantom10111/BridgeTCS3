#ifndef _STANDARD52DECK_H
#define _STANDARD52DECK_H
#include "Card.hpp"
#include "Deck.hpp"
#include <vector>
class BridgeDeck: public Deck{
	public:
		BridgeDeck();
		Card& getCard();
		void shuffle();
	private:
		std::vector<Card>& cards;
};
#endif
