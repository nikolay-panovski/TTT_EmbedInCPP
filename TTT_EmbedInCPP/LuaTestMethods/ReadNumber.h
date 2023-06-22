#pragma once

#include "LuaTestMethod.h"

class ReadNumber : public LuaTestMethod
{
	public:
		void Run(lua_State* lua) override;
};

