#ifndef IOBSERVABLE_HPP
#define IOBSERVABLE_HPP

#include <set>

#include "IObserver.hpp"

template<class T>
class IObservable
{
	std::set<IObserver<T> *> observers;

	protected:
	void notifyAll() const;

	public:
	void attach(IObserver<T> &);
	void detach(IObserver<T> &);
};

template<class T>
inline void IObservable<T>::attach(IObserver &observer)
{
	observers.insert(&observer);
}

template<class T>
inline void IObservable<T>::detach(IObserver &observer)
{
	observers.erase(&observer);
}

template<class T>
inline void IObservable<T>::notifyAll() const
{
	for(IObserver *observer : observers)
		observer->notify();
}

#endif
