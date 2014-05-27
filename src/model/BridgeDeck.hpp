#ifndef BRIDGEDECK_HPP
#define BRIDGEDECK_HPP
#include "model/Card.hpp"
#include "model/IDeck.hpp"
#include <vector>

namespace model {

class BridgeDeck: public IDeck{
	public:
		BridgeDeck(BridgeDeck&) = delete;
		BridgeDeck(BridgeDeck&&) = delete;
		BridgeDeck();
		Card getCard();
		void shuffle();
	private:
		std::vector<Card> cards;
};

}

#endif
