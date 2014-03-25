#ifndef BRIDGEDECK_HPP
#define BRIDGEDECK_HPP
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
