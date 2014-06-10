#include "Printer.hpp"

namespace ui
{
namespace text
{

#ifdef UNICODE
	const std::map<model::Suit, std::string> Printer::SuitRepr = {
		{model::Suit::CLUBS, "♣"},
		{model::Suit::DIAMONDS, "♢"},
		{model::Suit::HEARTS, "♡"},
		{model::Suit::SPADES, "♠"}
	};
#else
	const std::map<model::Suit, std::string> Printer::SuitRepr = {
		{model::Suit::CLUBS, "C"},
		{model::Suit::DIAMONDS, "D"},
		{model::Suit::HEARTS, "H"},
		{model::Suit::SPADES, "S"}
	};
#endif

void Printer::print(model::Suit suit)
{
	std::cout << Printer::SuitRepr.at(suit);
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
		switch(call.denomination)
		{
		case model::Denomination::CLUBS:
			std::cout << Printer::SuitRepr.at(model::Suit::CLUBS);
			break;
		case model::Denomination::DIAMONDS:
			std::cout << Printer::SuitRepr.at(model::Suit::DIAMONDS);
			break;
		case model::Denomination::HEARTS:
			std::cout << Printer::SuitRepr.at(model::Suit::HEARTS);
			break;
		case model::Denomination::SPADES:
			std::cout << Printer::SuitRepr.at(model::Suit::SPADES);
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

void Printer::print(std::vector<model::Card> const * cardsView){
	std::vector<model::Rank> sortedHand[4];
	for(model::Card c : *cardsView)
		sortedHand[static_cast<int>(c.suit)].push_back(c.rank);
	static const char map[4]={'c', 'd', 'h', 's'};
	for(int i = 0;i<4;i++)
	{
		Printer::print(static_cast<model::Suit>(i));
		//std::cout << " (" << map[i] << "): ";
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
