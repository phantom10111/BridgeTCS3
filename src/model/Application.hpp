#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ui/IObservable.hpp"

namespace model {

class Application : public ui::IObservable<Application>
{
public:
	void run(){
		notifyAll();
	}
};

}

#endif
