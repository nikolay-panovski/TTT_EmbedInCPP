#pragma once

#include "LuaTestMethod.h"

class Test1 : public LuaTestMethod
{
	private:
		int sumWithLua(int luaNumber, int cppNumber);
	public:
		void Run(lua_State* lua) override;
};

