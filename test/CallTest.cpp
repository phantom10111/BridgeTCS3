#include <gtest/gtest.h>

#include "Call.cpp"

TEST(Call, CallCreation)
{
	Call* doubleCall = new Call(CallType::DOUBLE);
	ASSERT_TRUE(doubleCall->callType == CallType::DOUBLE);
	delete doubleCall;

	Call* redoubleCall = new Call(CallType::REDOUBLE);
	ASSERT_TRUE(redoubleCall->callType == CallType::REDOUBLE);
	delete redoubleCall;

	Call* passCall = new Call(CallType::PASS);
	ASSERT_TRUE(passCall->callType == CallType::PASS);
	delete passCall;
}

TEST(DeclarationCall, DeclarationCallCreation)
{
	DeclarationCall* declarationCall = new DeclarationCall(Level::ACE);
	ASSERT_TRUE(declarationCall->callType == CallType::DECLARATION);
	ASSERT_TRUE(declarationCall->level == Level::ACE);
	delete declarationCall;
}
