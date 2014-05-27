#ifndef CONSOLEPLAYER_HPP
#define CONSOLEPLAYER_HPP

#include <istream>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>
#include "model/Call.hpp"
#include "model/Card.hpp"
#include "model/IPlayer.hpp"
#include "model/Trick.hpp"
#include "ui/text/Printer.hpp"

namespace ui {

namespace text {

class ConsolePlayer : public model::IPlayer
{
public:
	ConsolePlayer(std::istream&);
	void connectGameState(const std::vector<model::Card>& cardsView, const std::vector<model::Call>& callsView, const std::vector<model::Trick>& tricksView);
	void connectDummyHand(const std::vector<model::Card>& cardsView);
	model::Card getCard();
	model::Card getDummyCard();
	model::Call getCall();
	
private:
	std::istream& stream; 
	std::vector<model::Card> const * cardsView;
	std::vector<model::Call> const* callsView;
	std::vector<model::Trick> const* tricksView;
	std::vector<model::Card> const* dummyView;
	static std::string const prompt;
	
	template <class T>
	T readChar(std::map<char, T> map, std::string message);
	
	model::Card getCardFrom(std::vector<model::Card> const * cardsView, std::string message);
	int readIntFromRange(int lowerBound, int upperBound, std::string message);
};

template <class T>
T ConsolePlayer::readChar(std::map<char, T> map, std::string message){
	char c= '\0';
	while(!map.count(c)){
		std::cout << message << std::endl;
		std::cout << prompt;
		stream >> c;
	}
	return map[c];
}

} // namespace text

} // namespace ui

#endif
