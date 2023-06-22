#pragma once

#include "LuaTestMethod.h"

class ReadString : public LuaTestMethod
{
public:
	void Run(lua_State* lua) override;
};

