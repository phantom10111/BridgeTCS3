#ifndef UI_TEXT_HAND_HPP
#define UI_TEXT_HAND_HPP

#include "ui/text/Printer.hpp"
#include "model/Hand.hpp"

namespace ui
{
namespace text
{

class Hand
{
	void notify(const model::Hand& hand);
};

}
}

#endif