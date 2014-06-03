#include "ui/text/ConsolePlayer.hpp"

namespace ui {

namespace text {
std::string const ConsolePlayer::prompt("> ");
ConsolePlayer::ConsolePlayer(std::istream& stream): stream(stream){}

void ConsolePlayer::connectGameState(const std::vector<model::Card>& cardsView, const std::vector<model::Call>& callsView, const model::Play::Tricks & tricksView)
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
		if(!(stream >> input))
		{
			input = upperBound + 1;
			stream.clear();
			stream.ignore(std::numeric_limits<std::streamsize>::max(), stream.widen('\n'));
		}
	}
	return input;
}

model::Card ConsolePlayer::getCardFrom(std::vector<model::Card> const * cardsView, std::string message){
	std::vector<model::Rank> sortedHand[4];
	for(model::Card c : *cardsView)
		sortedHand[static_cast<int>(c.suit)].push_back(c.rank);
	unsigned int choice = 0;
	while(choice == 0 || choice > cardsView->size())
	{
		unsigned int cardIndex = 1;
		for(int i = 0;i<4;i++)
		{
			Printer::print(static_cast<model::Suit>(i));
			std::cout << ": ";
			std::sort(sortedHand[i].begin(), sortedHand[i].end(), std::greater<model::Rank>());
			for(model::Rank r : sortedHand[i])
			{
				Printer::print(r);
				std::cout << " (" << cardIndex << ") ";
				cardIndex++;
			}
			std::cout << std::endl;
		}
		std::cout << prompt;
		if(!(stream >> choice))
		{
			stream.clear();
			stream.ignore(std::numeric_limits<std::streamsize>::max(), stream.widen('\n'));
		}
	}

	for(int i = 0;i<4;i++)
	{
		for(model::Rank r : sortedHand[i])
		{
			if(choice == 1)
				return model::Card(static_cast<model::Suit>(i), r);
			choice--;
		}
	}
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
