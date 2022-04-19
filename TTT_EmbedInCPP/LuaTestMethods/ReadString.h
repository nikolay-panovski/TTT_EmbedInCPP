#pragma once

#include "TestMethod.h"

class ReadString : public TestMethod
{
public:
	void Run(lua_State* lua) override;
};

