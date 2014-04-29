#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ui/IObservable.hpp"
#include "ui/text/Application.hpp"

namespace model {

class Application : IObservable<ui::text::Application>
{
public:
	void run(){
		notifyAll();
	}
};

}

#endif
