#include "model/Card.hpp"
Card::Card(Suit suit, Rank rank)
{
	this->rank=rank;
	this->suit=suit;
}
bool operator ==(Card const &a, Card const &b){
	return a.suit==b.suit && a.rank==b.rank;
}
