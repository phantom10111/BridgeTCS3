#ifndef _CALL_HPP_
#define _CALL_HPP_

#include "CallType.hpp"
#include "Level.hpp"
#include "Denomination.hpp"

class Call
{
	private:
	Level level;
	Denomination denomination;
	
	Call(CallType);
	Call(CallType, Level, Denomination);
	
	public:

	static Call pass();
	static Call dbl();
	static Call redbl();
	static Call bid(Level, Denomination);
	
};

#endif
