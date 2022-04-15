#pragma once

#include <lua.hpp>
#include <iostream>
#include <string>

#include "TestMethod.h"

class TestRunner
{
	private:
		lua_State* lua;

	public: 
		TestRunner(const char* filename, TestMethod& runMethod, bool printError = true);
		~TestRunner();
};

