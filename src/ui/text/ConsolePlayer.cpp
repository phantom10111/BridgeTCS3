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

// read<Call>({{'p', Call::PASS()}, {'d', Call::DOUBLE()}});

// read()

model::Call ConsolePlayer::getCall()
{
	model::CallType response = readChar<model::CallType>({{'p', model::CallType::PASS}, {'d', model::CallType::DOUBLE}, {'r', model::CallType::REDOUBLE}, {'b', model::CallType::BID}}, "Choose call type: p - pass, d - double, r - redouble, b - bid");
	
	switch(response)
	{
		case model::CallType::PASS:
			return model::Call::PASS();
		case model::CallType::DOUBLE:
			return model::Call::DOUBLE();
		case model::CallType::REDOUBLE:
			return model::Call::REDOUBLE();
		case model::CallType::BID:
			{
				//int level=readIntFromRange(1, 7, "Choose level");
				int level = readChar<int>({{'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}}, "Choose level");
				model::Denomination denomination=readChar<model::Denomination>({{'c', model::Denomination::CLUBS}, {'d', model::Denomination::DIAMONDS}, {'h', model::Denomination::HEARTS}, {'s', model::Denomination::SPADES}, {'n', model::Denomination::NO_TRUMP}}, "Choose denomination: c - clubs, d - diamonds, h - hearts, s - spades, n - no trump");
				return model::Call::BID(level, denomination);
			}
		default:
			throw "That's never gonna happen";
	}
}

} // namespace text

} // namespace ui
