#ifndef CONSOLEPLAYER_HPP
#define CONSOLEPLAYER_HPP

#include <istream>
#include "model/IPlayer.hpp"

namespace ui {

namespace text {

class ConsolePlayer : public model::IPlayer
{
public:
	ConsolePlayer(std::istream&);
	void connectGameState(const std::vector<Card>& cardsView, const std::vector<Call>& callsView, const std::vector<Trick>& tricksView);
	void connectDummyHand(const std::vector<Card>& cardsView);
	Card getCard();
	Card getDummyCard();
	Call getCall();
private:
	std::istream& stream; 
	std::vector<Card> const * cardsView;
	std::vector<Call> const* callsView;
	std::vector<Trick> const* tricksView;
	std::vector<Card> const* cardsView
};

} // namespace text

} // namespace ui

#endif
