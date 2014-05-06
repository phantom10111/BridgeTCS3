#ifndef IOBSERVABLE_HPP
#define IOBSERVABLE_HPP

#include <set>
#include <boost/signals2/signal.hpp>

namespace ui {

template <class Derived>
class IObservable
{

	public:
	boost::signals2::signal<void (Derived const&)> sigModified;
};

} // namespace ui

#endif
