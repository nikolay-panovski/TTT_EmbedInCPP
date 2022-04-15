#pragma once

#include "TestMethod.h"

class Test1 : public TestMethod
{
	private:
		int sumWithLua(int luaNumber, int cppNumber);
	public:
		void Run(lua_State* lua) override;
};

