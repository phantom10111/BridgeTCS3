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
	static Call PASS();
	static Call DOUBLE();
	static Call REDOUBLE();
	static Call BID(int level, Denomination);
	
};

#endif
