#ifndef IOBSERVABLE_HPP
#define IOBSERVABLE_HPP

#include <set>

#include "ui/IObserver.hpp"

namespace ui {

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
inline void IObservable<T>::attach(IObserver<T> &observer)
{
	observers.insert(&observer);
}

template<class T>
inline void IObservable<T>::detach(IObserver<T> &observer)
{
	observers.erase(&observer);
}

template<class T>
inline void IObservable<T>::notifyAll() const
{
	for(IObserver<T> *observer : observers)
		observer->notify(*static_cast<T const *>(this));
}

}

#endif
