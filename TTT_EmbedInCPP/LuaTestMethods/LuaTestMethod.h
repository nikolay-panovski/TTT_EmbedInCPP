#pragma once

#include <lua.hpp>
#include <iostream>
#include <string>

class LuaTestMethod
{
	public:
		virtual void Run(lua_State* lua) = 0;
};

