#include "model/Call.hpp"
#include "model/Denomination.hpp"

#include <stdexcept>

Call::Call(CallType type) :
	type(type),
	level(0),
	denomination(Denomination::VOID)
{ }

Call::Call(CallType type, int level, Denomination denomination) : 
	type(type),
	level(level),
	denomination(denomination)
{ }

Call Call::PASS()
{
	return Call(CallType::PASS);
}

Call Call::DOUBLE()
{
	return Call(CallType::DOUBLE);
}

Call Call::REDOUBLE()
{
	return Call(CallType::REDOUBLE);
}

Call Call::BID(int level, Denomination denomination)
{
	if(level < 1 || level > 7)
		throw std::invalid_argument("Incorrect level");
	return Call(CallType::BID, level, denomination);
}
