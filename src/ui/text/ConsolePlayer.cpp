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
	Printer::print(cardsView);
	
	model::Rank rank = readChar<model::Rank>({
		{'2', model::Rank::TWO},
		{'3', model::Rank::THREE},
		{'4', model::Rank::FOUR},
		{'5', model::Rank::FIVE},
		{'6', model::Rank::SIX},
		{'7', model::Rank::SEVEN},
		{'8', model::Rank::EIGHT},
		{'9', model::Rank::NINE},
		{'T', model::Rank::TEN},
		{'J', model::Rank::JACK},
		{'Q', model::Rank::QUEEN},
		{'K', model::Rank::KING},
		{'A', model::Rank::ACE}
	},
	"Choose rank: 2-9, T, J, K, A");
	
	model::Suit suit = readChar<model::Suit>({
		{'c', model::Suit::CLUBS},
		{'d', model::Suit::DIAMONDS},
		{'h', model::Suit::HEARTS},
		{'s', model::Suit::SPADES}
	},
	"Choose suit: c - clubs, d - diamonds, h - hearts, s - spades");
	
	return model::Card(suit, rank);
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
	Printer::print(cardsView);

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
