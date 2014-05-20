#include "model/BridgeDeck.hpp"
#include <algorithm>
#include <exception>
#include <random>

namespace model {

BridgeDeck::BridgeDeck()
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
void BridgeDeck::shuffle()
{
	std::shuffle(cards.begin(), cards.end(), std::random_device());
}
Card BridgeDeck::getCard()
{
	if(cards.size()==0){
		throw std::exception();
	}
	Card c = cards[cards.size()-1];
	cards.pop_back();
	return c;
}

}
