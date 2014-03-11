#ifndef _CALL_HPP_
#define _CALL_HPP_

#include "CallType.hpp"
#include "Level.hpp"

class Call
{
	public:

	CallType callType;

	Call(CallType);
};

class DeclarationCall : public Call
{
	public:

	Level level;

	DeclarationCall(Level);
};

#endif
