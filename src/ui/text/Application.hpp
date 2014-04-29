#ifndef UI_TEXT_APPLICATION_HPP
#define UI_TEXT_APPLICATION_HPP

#include <iostream>

#include "ui/IObserver.hpp"
#include "model/Application.hpp"

namespace ui {
namespace text {

class Application : public ui::IObserver<model::Application>
{
	virtual void notify(const model::Application& obj) {
		std::cout << "Hello world!" << std::endl;
	}
};

}
}

#endif
