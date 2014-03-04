#ifndef _CARD_H
#define _CARD_H

enum class Suit
{
	SPADE,
	HEART,
	DIAMOND,
	CLUB
};

enum class Rank
{
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

struct Card
{
	public:
	Suit suit;
	Rank rank;
	Card(Suit, Rank);
};

#endif
