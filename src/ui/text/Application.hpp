#ifndef UI_TEXT_APPLICATION_HPP
#define UI_TEXT_APPLICATION_HPP

#include <iostream>

#include "model/Application.hpp"

namespace ui {
namespace text {

class Application
{
public:
	void notify(const model::Application& obj) {
		std::cout << "Hello world!" << std::endl;
	}
};

}
}

#endif
