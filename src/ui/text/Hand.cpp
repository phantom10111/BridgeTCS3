#include "ui/text/Hand.hpp"

namespace ui
{
namespace text
{

void Hand::notify(const model::Hand& hand)
{
	std::cout << "Hand contains:" << std::endl;
	for(model::Card card : hand.getCardsView())
	{
		Printer::print(card);
	}
	std::cout << std::endl;
}
}
}