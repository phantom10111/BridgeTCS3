#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

namespace ui {

template <class T>
class IObserver
{
public:
	virtual void notify(const T& obj) = 0;
};

}

#endif
