
#include "model/ArbiterCycle.hpp"

namespace model {

void ArbiterCycle::next()
{
	i = (i + 1) % 4;
	sigModified(*this);
}

Arbiter& ArbiterCycle::current()
{
	return data[i];
}

Arbiter& ArbiterCycle::getAt(int i)
{
	return data[i];
}

void ArbiterCycle::rotateTo(int j){
	i = j;
	sigModified(*this);
}

int ArbiterCycle::getIndex() const {
	return i;
}

}
