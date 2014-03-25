#ifndef _BRIDGEDECK_H
#define _BRIDGEDECK_H
#include "Card.hpp"
#include "IDeck.hpp"
#include <vector>
class BridgeDeck: public IDeck{
	public:
		BridgeDeck();
		Card getCard();
		void shuffle();
	private:
		std::vector<Card const *> cards;
};
#endif
