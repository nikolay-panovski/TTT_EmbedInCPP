#pragma once

#include <lua.hpp>
#include <iostream>
#include <string>

#include "LuaTestMethods/TestRunner.h"
#include "LuaTestMethods/Test0.h"
#include "LuaTestMethods/Test1.h"
#include "LuaTestMethods/Test2.h"

using namespace std;

int main(int argc, char* argv[]) {
	Test0 test0;
	Test1 test1;
	Test2 test2;

	/** TestRunner wraps Lua initialization & close code.
	 *  Open the corresponding .lua file for the Lua code and Test#.cpp for the C++ code.
	 *  Optionally choose whether to print status/error code after the loadfile.
	 */
	TestRunner testRunner("array_print.lua", test2, true);	

	//TestRunner testRunner("helloworld.lua", test1, false);	// Lua file + test number mismatch handled in the test1.Run()

	return 0;
}