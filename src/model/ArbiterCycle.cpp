
#include "model/ArbiterCycle.hpp"

namespace model {

Arbiter& ArbiterCycle::next()
{
	Arbiter& res = data[i];
	++i;
	if(i == 4)
		i = 0;
	return res;
}

Arbiter& ArbiterCycle::getAt(int i)
{
	return data[i];
}

void ArbiterCycle::rotateTo(int j){
	i = j;
}

int ArbiterCycle::getIndex(){
	return i;
}

}
