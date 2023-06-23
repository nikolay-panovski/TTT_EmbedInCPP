//#define MEASURE_PROGRAM

#pragma once

#include <iostream>
#include <string>

#include <chrono>

#include "LuaTestMethods/LuaTestRunner.h"
#include "JSTestMethods/JSTestRunner.h"

#include "Entities/Player.h"

//#include "LuaTestMethods/OverwritePlayerVar_LuaToCPP.h"
//#include "JSTestMethods/OverwritePlayerVar_JSToCPP.h"
//#include "LuaTestMethods/ReadPlayerVar_LuaToCPP.h"
//#include "JSTestMethods/ReadPlayerVar_JSToCPP.h"
#include "LuaTestMethods/ChangePlayerStats_LuaToCPP.h"
#include "JSTestMethods/ChangePlayerStats_JSToCPP.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
	// OBSOLETE SECTION: Initial tests with Lua in C++ (structured in classes).
	/**
	Test0 test0;
	Test1 test1;
	Test2 test2;
	ReadNumber readNumber;
	ReadString readString;
	/**/

	Player player;

	//OverwritePlayerVar_LuaToCPP test1_var_lua(&player);
	//OverwritePlayerVar_JSToCPP test1_var_js(&player);

	//ReadPlayerVar_LuaToCPP test2_var_lua(&player);
	//ReadPlayerVar_JSToCPP test2_var_js(&player);

	ChangePlayerStats_LuaToCPP test3_stats_lua(&player);
	ChangePlayerStats_JSToCPP test3_stats_js(&player);

	printf_s("Entering functional method.\n");

	high_resolution_clock::time_point start = high_resolution_clock::now();

	// TestRunners wrap Lua/JS initialization & close code.
	// Open the corresponding files in /_TestMethods folders for embedded code and <subclass of TestMethod>.cpp for the C++ code.
	// Specify a filename to write measurements into.
	// Optionally specify number of samples to repeat the whole test for, and number of runs per each sample (else both are 1).
	// Optionally choose whether to print status/error code after the loadfile.

	// NOTE: Please ensure a directory ALREADY EXISTS, if trying to write a file in a directory.
	// No easy way to create/ensure that within code (~~C++17 adds something, too much effort for a detail here though.)
	
	// SECTION: Final tests (via class instances above + TestRunners below).
	//LuaTestRunner luaTestRunner("LuaTestMethods/overwritevar_lua.lua", "Measures/test1_var_lua.csv", test1_var_lua, 1000, 60, false);
	//JSTestRunner jsTestRunner("JSTestMethods/overwritevar_js.js", "Measures/test1_var_js.csv", test1_var_js, 1000, 60, false);
	//LuaTestRunner luaTestRunner("LuaTestMethods/readvar_lua.lua", "Measures/test2_var_lua.csv", test2_var_lua, 1000, 60, false);
	//JSTestRunner jsTestRunner("JSTestMethods/readvar_js.js", "Measures/test2_var_js.csv", test2_var_js, 1000, 60, false);
	//LuaTestRunner luaTestRunner("LuaTestMethods/changestats_lua.lua", "Measures/test3_stats_lua.csv", test3_stats_lua, 1000, 60, false);
	JSTestRunner jsTestRunner("JSTestMethods/changestats_js.js", "Measures/test3_stats_js.csv", test3_stats_js, 1000, 60, false);


	high_resolution_clock::time_point end = high_resolution_clock::now();

	#ifdef MEASURE_PROGRAM
	LuaTestRunner::MeasureTime(start, end, "Complete execution");
	#endif

	printf_s("Exiting functional method.\n");

	return 0;
}