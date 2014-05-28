#ifndef BRIDGEDECK_HPP
#define BRIDGEDECK_HPP
#include "model/Card.hpp"
#include "model/IDeck.hpp"
#include <algorithm>
#include <exception>
#include <utility>
#include <vector>

namespace model {

template<typename URNG>
class RandomDeck: public IDeck{
	public:
		RandomDeck(RandomDeck&) = delete;
		RandomDeck(RandomDeck&&) = delete;

		template<typename... Args>
		RandomDeck(Args... args) : generator(std::forward<Args>(args)...)
		{
			Suit suits[]={Suit::SPADES, Suit::HEARTS, Suit::DIAMONDS, Suit::CLUBS};
			Rank ranks[]={Rank::TWO, Rank::THREE, Rank::FOUR, Rank::FIVE, Rank::SIX, Rank::SEVEN, Rank::EIGHT, Rank::NINE, Rank::TEN, Rank::JACK, Rank::QUEEN, Rank::KING, Rank::ACE};
			for(Suit s: suits)
			{
				for(Rank r: ranks)
				{
					cards.push_back(Card(s, r));
				}
			}
		}

		Card getCard()
		{
			if(cards.size()==0){
				throw std::exception();
			}
			Card c = cards[cards.size()-1];
			cards.pop_back();
			return c;
		}

		void shuffle()
		{
			std::shuffle(cards.begin(), cards.end(), generator);
		}

	private:
		URNG generator;
		std::vector<Card> cards;
};

}

#endif
