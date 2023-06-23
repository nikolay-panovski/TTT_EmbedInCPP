#pragma once

#include "LuaTestMethod.h"

class Test0 : public LuaTestMethod
{
	public:
		void Run(lua_State* lua) override;
};