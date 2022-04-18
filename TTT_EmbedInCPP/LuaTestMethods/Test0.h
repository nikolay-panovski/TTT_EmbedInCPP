#pragma once

#include "TestMethod.h"

class Test0 : public TestMethod
{
	public:
		void Run(lua_State* lua) override;
};