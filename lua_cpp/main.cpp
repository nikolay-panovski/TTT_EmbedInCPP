#pragma once

#include <lua.hpp>
#include <iostream>
#include <string>

#include "LuaTestMethods/TestRunner.h"
#include "LuaTestMethods/Test0.h"
#include "LuaTestMethods/Test1.h"

using namespace std;

int main(int argc, char* argv[]) {
	Test0 test0;
	Test1 test1;

	/** TestRunner wraps Lua initialization & close code.
	 *  Open the corresponding .lua file for the Lua code and Test#.cpp for the C++ code.
	 */
	TestRunner testRunner("crossglobal.lua", test1, false);	

	//TestRunner testRunner("helloworld.lua", test1, false);	// Lua file + test number mismatch handled in the test1.Run()

	return 0;
}