#pragma once

#include "TestMethod.h"

class ReadNumber : public TestMethod
{
	public:
		void Run(lua_State* lua) override;
};

