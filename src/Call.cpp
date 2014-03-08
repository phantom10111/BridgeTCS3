#include "Call.hpp"

Call::Call(CallType callType)
{
	this->callType = callType;
}

DeclarationCall::DeclarationCall(Level level) : Call(CallType::DECLARATION)
{
	this->level = level;
}
