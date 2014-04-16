#include "IObservable.hpp"
#include "IObserver.hpp"

void IObservable::attach(IObserver &observer)
{
	observers.insert(&observer);
}

void IObservable::detach(IObserver &observer)
{
	observers.erase(&observer);
}

void IObservable::notifyAll() const
{
	for(IObserver *observer : observers)
		observer->notify();
}
