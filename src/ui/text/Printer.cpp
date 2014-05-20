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
	for(auto & card : trick.getCardsView()){
		print(card);
	}
}

void Printer::print(model::Call const & call)
{
	switch(call.type)
	{
	case model::CallType::BID:
		std::cout << call.level;
		switch(call.denomination)
		{
		case model::Denomination::CLUBS:
			std::cout << "♣";
			break;
		case model::Denomination::DIAMONDS:
			std::cout << "♢";
			break;
		case model::Denomination::HEARTS:
			std::cout << "♡";
			break;
		case model::Denomination::SPADES:
			std::cout << "♠";
			break;
		case model::Denomination::NO_TRUMP:
			std::cout << "NT";
			break;
		}
		break;
	case model::CallType::DOUBLE:
		std::cout << "Double";
		break;
	case model::CallType::REDOUBLE:
		std::cout << "Redouble";
		break;
	case model::CallType::PASS:
		std::cout << "Pass";
		break;
	}
}

}
}
