#ifndef _CALL_HPP_
#define _CALL_HPP_

#include "CallType.hpp"
#include "Denomination.hpp"

class Call
{
	private:
	int level;
	Denomination denomination;
	
	Call(CallType);
	Call(CallType, int level, Denomination);
	
	public:
	static Call pass();
	static Call dbl();
	static Call redbl();
	static Call bid(int level, Denomination);
	
};

#endif
