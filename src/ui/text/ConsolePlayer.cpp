#include "ui/text/ConsolePlayer.hpp"

namespace ui {

namespace text {
std::string const ConsolePlayer::prompt("> ");
ConsolePlayer::ConsolePlayer(std::istream& stream): stream(stream){}

void ConsolePlayer::connectGameState(const std::vector<model::Card>& cardsView, const std::vector<model::Call>& callsView, const std::vector<model::Trick>& tricksView)
{
	this->cardsView = &cardsView;
	this->callsView = &callsView;
	this->tricksView = &tricksView;
	return;
}

void ConsolePlayer::connectDummyHand(const std::vector<model::Card>& cardsView)
{
	this->dummyView=&cardsView;
	return;
}

int ConsolePlayer::readIntFromRange(int lowerBound, int upperBound, std::string message){
	int input = upperBound+1;
	while(input < lowerBound || input > upperBound )
	{
		std::cout<< message <<std::endl;
		std::cout << prompt;
		stream >> input;
	}
	return input;
}

model::Card ConsolePlayer::getCardFrom(std::vector<model::Card> const * cardsView, std::string message){
	unsigned int cardIndex = 0;
	while(cardIndex == 0 || cardIndex > cardsView->size())
	{
		std::cout<< message <<std::endl;
		int index = 1;
		for(model::Card card : *cardsView)
		{
			std::cout << index << ' ';
			Printer::print(card);
			std::cout << ' ';
			index++;
		}
		std::cout << std::endl << prompt;
		stream >> cardIndex;
	}
	
	return (*cardsView)[cardIndex - 1];
}

model::Card ConsolePlayer::getCard()
{
	return getCardFrom(cardsView, "Throw a card, sire");
}

model::Card ConsolePlayer::getDummyCard()
{
	return getCardFrom(dummyView, "Throw a dummy card, sir");
}

model::Call ConsolePlayer::getCall()
{
	int response = readIntFromRange(1, 4, "Choose call type: 1 - pass, 2 - double, 3 - redouble, 4 - bid");
	
	switch(response)
	{
		case 1:
			return model::Call::PASS();
		case 2:
			return model::Call::DOUBLE();
		case 3:
			return model::Call::REDOUBLE();
		case 4:
			{
				int level=readIntFromRange(1, 7, "Choose level");
				int denomination=readIntFromRange(1, 5, "Choose denomination: 1 - clubs, 2 - diamonds, 3 - hearts, 4 - spades, 5 - no trump");
				return model::Call::BID(level, static_cast<model::Denomination>(denomination - 1));
			}
		default:
			throw "That's never gonna happen";
	}
}

} // namespace text

} // namespace ui
