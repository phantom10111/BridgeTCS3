#include "Printer.hpp"

namespace ui
{
namespace text
{

void Printer::print(model::Suit suit)
{
	switch(suit)
	{
		case model::Suit::CLUBS:
			std::cout << "♣";
			break;
		case model::Suit::DIAMONDS:
			std::cout << "♢";
			break;
		case model::Suit::HEARTS:
			std::cout << "♡";
			break;	
		case model::Suit::SPADES:
			std::cout << "♠";
			break;	
	}
}

void Printer::print(model::Rank rank)
{
	if(static_cast<int>(rank) <= 8)
	{
		std::cout << static_cast<int>(rank) + 2;
		return;
	}
	switch(rank)
	{
		case model::Rank::ACE:
			std::cout << "A";
			break;
		case model::Rank::KING:
			std::cout << "K";
			break;
		case model::Rank::QUEEN:
			std::cout << "Q";
			break;
		case model::Rank::JACK:
			std::cout << "J";
			break;
	}
}

void Printer::print(model::Card card)
{
	std::cout << "[";
	print(card.rank);
	print(card.suit);
	std::cout << "]";
}

void Printer::print(model::Trick const & trick)
{
	for(Card card : trick.getCardsView){
		print(card);
	}
}

}
}
