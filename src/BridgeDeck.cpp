#include "BridgeDeck.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>

BridgeDeck::BridgeDeck()
{
	Suit suits[]={Suit::SPADES, Suit::HEARTS, Suit::DIAMONDS, Suit::CLUBS};
	Rank ranks[]={Rank::TWO, Rank::THREE, Rank::FOUR, Rank::FIVE, Rank::SIX, Rank::SEVEN, Rank::EIGHT, Rank::NINE, Rank::TEN, Rank::JACK, Rank::QUEEN, Rank::KING, Rank::ACE};
	for(Suit s: suits)
	{
		for(Rank r: ranks)
		{
			cards.push_back(new Card(s, r));
		}
	}
}
void BridgeDeck::shuffle()
{
	std::srand ( unsigned ( std::time(0) ) );
	std::random_shuffle(cards.begin(), cards.end());
}
Card& BridgeDeck::getCard()
{
	//return cards[0];
}
