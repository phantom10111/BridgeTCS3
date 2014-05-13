#include "ui/text/ConsolePlayer.hpp"

namespace ui {

namespace text {

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

model::Card ConsolePlayer::getCard()
{
	std::cout<<"Rzuc pan karte"<<std::endl;
	for(model::Card card : *cardsView)
	{
		
	}
}

model::Card ConsolePlayer::getDummyCard()
{
	//return Card(0, 0);
}

model::Call ConsolePlayer::getCall()
{
	//return getRandomCall();
}

} // namespace text

} // namespace ui
