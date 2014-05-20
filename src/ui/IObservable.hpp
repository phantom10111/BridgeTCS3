#ifndef IOBSERVABLE_HPP
#define IOBSERVABLE_HPP

#include <boost/signals2/signal.hpp>

namespace ui {

template <class Derived>
class IObservable
{

	public:
	mutable boost::signals2::signal<void (Derived const&)> sigModified;
};

} // namespace ui

#endif
