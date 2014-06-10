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
	if(static_cast<int>(rank) <= static_cast<int>(model::Rank::NINE))
	{
		std::cout << static_cast<int>(rank) + 2;
		return;
	}
	switch(rank)
	{
		case model::Rank::TEN:
			std::cout << "T";
			break;
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
		print(call.denomination);
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

void Printer::print(model::Denomination denomination)
{
	switch(denomination)
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
}

void Printer::print(model::Contract const & contract)
{
	std::cout << "Contract: ";
	if(contract.level==0)
		std::cout << "4 Passes" << std::endl;
	else
	{
		std::cout << contract.level;
		print(contract.denomination);
		if(contract.multiplier == 2)
			std::cout << " doubled";
		else if(contract.multiplier == 4)
			std::cout << " redoubled";
		std::cout << std::endl << "Player: " << contract.player << std::endl;
	}
}

void Printer::print(model::DealResult const & result)
{
	print(result.contract);
	if(result.contract.level!=0){
		std::cout << "Tricks won: " << result.tricksWon << std::endl;	
	}
}

void Printer::print(std::vector<model::Card> const * cardsView){
	std::vector<model::Rank> sortedHand[4];
	for(model::Card c : *cardsView)
		sortedHand[static_cast<int>(c.suit)].push_back(c.rank);
	static const char map[4]={'c', 'd', 'h', 's'};
	for(int i = 0;i<4;i++)
	{
		Printer::print(static_cast<model::Suit>(i));
		std::cout << " : ";
		std::sort(sortedHand[i].begin(), sortedHand[i].end(), std::greater<model::Rank>());
		for(model::Rank r : sortedHand[i])
		{
			Printer::print(r);
			std::cout<<" ";
		}
		std::cout << std::endl;
	}
}

}
}
