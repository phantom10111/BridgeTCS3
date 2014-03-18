#include "Call.hpp"
#include "CallType.hpp"
#include "Denomination.hpp"

#include <stdexcept>

Call Call::pass()
{
	return Call(CallType::PASS);
}

Call Call::dbl()
{
	return Call(CallType::DOUBLE);
}

Call Call::redbl()
{
	return Call(CallType::REDOUBLE);
}

Call Call::bid(int level, Denomination denomination)
{
	if(level < 1 || level > 7)
		throw std::invalid_argument("Incorrect level");
	return Call(CallType::BID, level, denomination);
}
