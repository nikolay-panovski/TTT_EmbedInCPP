#pragma once

#include <lua.hpp>
#include <iostream>
#include <string>

#include <chrono>

#include "LuaTestMethods/TestRunner.h"
#include "LuaTestMethods/Test0.h"
#include "LuaTestMethods/Test1.h"
#include "LuaTestMethods/Test2.h"

using namespace std;
using namespace std::chrono;

// Runs the core part of the C++ method handling Lua script - similar wrapping setup to TestRunner.
// Add functional code only here.
void runLuaMethod(lua_State* lua, int runCount) {
	for (int i = 1; i <= runCount; i++) {

		lua_getglobal(lua, "readVar");

		if (lua_isnumber(lua, -1)) {
			int numFromLua = lua_tonumber(lua, -1);

			//printf_s("Number: %i\n", numFromLua);		// do NOT print in actual performance tests.
		}

		lua_pop(lua, 1);
	}
}

void runScriptWithLua(const char* filename, bool printError = false) {
	lua_State* lua = luaL_newstate();
	luaL_openlibs(lua);

	if (printError) {
		if (luaL_loadfile(lua, filename) != LUA_OK) {
			printf_s("Error code: %s\n", lua_tostring(lua, -1));

			// TODO in good code: throw and handle an exception (god bless StackOverflow)
			// else runMethod.Run below will throw an exception
		}
		else {
			printf_s("LUA_OK: Lua file loaded fine.\n");
		}
	}
	else {
		luaL_loadfile(lua, filename);
	}

	lua_call(lua, 0, 0);	// lua_call(state, params, returns);

	printf_s("Entering functional method.\n");

	high_resolution_clock::time_point start = high_resolution_clock::now();

	/* functional code here - change THIS*/
	runLuaMethod(lua, 1000000);
	/* END of functional code here */

	high_resolution_clock::time_point end = high_resolution_clock::now();

	microseconds time_span = duration_cast<microseconds>(end - start);
	printf_s("Execution took %I64i microseconds.\n", time_span.count());

	printf_s("Exiting functional method.\n");

	lua_pop(lua, 1);

	lua_close(lua);
}

int main(int argc, char* argv[]) {

	// SECTION: Initial tests with Lua in C++ (structured in classes).
	/**
	Test0 test0;
	Test1 test1;
	Test2 test2;

	// TestRunner wraps Lua initialization & close code.
	// Open the corresponding .lua file for the Lua code and Test#.cpp for the C++ code.
	// Optionally choose whether to print status/error code after the loadfile.
	TestRunner testRunner("array_print.lua", test2, true);	

	//TestRunner testRunner("helloworld.lua", test1, false);	// Lua file + test number mismatch handled in the test1.Run()

	/**/

	runScriptWithLua("readInCPP_simple_onevar.lua", true);

	return 0;
}