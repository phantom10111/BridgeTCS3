#include "Call.hpp"
#include "CallType.hpp"
#include "Denomination.hpp"
#include "Level.hpp"

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

Call Call::bid(Level level, Denomination denomination)
{
	return Call(CallType::BID, level, denomination);
}
