#pragma once

#include "TestMethod.h"

class Test2 : public TestMethod
{
	public:
		void Run(lua_State* lua) override;
};

