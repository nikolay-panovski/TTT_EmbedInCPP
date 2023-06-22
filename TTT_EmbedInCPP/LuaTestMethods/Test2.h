#pragma once

#include "LuaTestMethod.h"

class Test2 : public LuaTestMethod
{
	public:
		void Run(lua_State* lua) override;
};

