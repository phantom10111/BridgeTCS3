#include "Card.hpp"
#include "Denomination.hpp"

class Trick
{
public:
	Trick(Denomination);
	void addCard(Card);
	int getWinner();
};
