
#include "model/ArbiterCycle.hpp"

namespace model {

Arbiter& ArbiterCycle::next()
{
	++i;
	if(i == 4)
		i = 0;
	sigModified(*this);
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
