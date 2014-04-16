#ifndef IOBSERVABLE_HPP
#define IOBSERVABLE_HPP

#include "IObserver.hpp"

#include <set>

class IObservable
{
	std::set<IObserver *> observers;

	protected:
	void notifyAll() const;

	public:
	void attach(IObserver &);
	void detach(IObserver &);
};

#endif
