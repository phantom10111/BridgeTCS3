#ifndef CALL_HPP
#define CALL_HPP

#include "Denomination.hpp"

enum class CallType
{
	BID,
	DOUBLE,
	REDOUBLE,
	PASS
};

class Call
{
	private:
	Call(CallType);
	Call(CallType, int level, Denomination);

	public:
	CallType type;
	int level;
	Denomination denomination;

	static Call PASS();
	static Call DOUBLE();
	static Call REDOUBLE();
	static Call BID(int level, Denomination);
};

#endif
