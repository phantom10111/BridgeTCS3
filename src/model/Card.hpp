#ifndef CARD_HPP
#define CARD_HPP

namespace model {

enum class Suit
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
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
	Suit suit;
	Rank rank;
	Card(Suit, Rank);
	bool operator==(Card const &a, Card const &b);
};

inline Card::Card(Suit suit, Rank rank)
{
	this->rank=rank;
	this->suit=suit;
}

inline bool operator ==(Card const &a, Card const &b){
	return a.suit==b.suit && a.rank==b.rank;
}

}

#endif
