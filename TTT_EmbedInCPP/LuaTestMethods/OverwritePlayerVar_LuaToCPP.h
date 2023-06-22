#pragma once

#include "LuaTestMethod.h"

class OverwritePlayerVar_LuaToCPP : public LuaTestMethod
{
	public:
		void Run(lua_State* lua) override;
};