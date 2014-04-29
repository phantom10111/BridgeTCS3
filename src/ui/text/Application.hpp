#ifndef UI_TEXT_APPLICATION_HPP
#define UI_TEXT_APPLICATION_HPP

#include "ui/IObserver.hpp"
#include "model/Application.hpp"

namespace ui {
namespace text {

class Application : IObserver< ::Application>
{
	virtual void notify(const ::Application& obj) {
		
	}
};

}
}

#endif
