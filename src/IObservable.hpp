#ifndef IOBSERVABLE_HPP
#define IOBSERVABLE_HPP

#include "IObserver.hpp"

#include <set>

class IObservable
{
	std::set<IObserver *> observers;

	protected:
	void notifyAll();

	public:
	void attach(IObserver &);
	void detach(IObserver &);
};

#endif
