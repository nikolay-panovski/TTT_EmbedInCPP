#pragma once

#include <lua.hpp>
#include <iostream>
#include <string>

#include <chrono>

#include "LuaTestMethods/TestRunner.h"

#include "LuaTestMethods/Test0.h"
#include "LuaTestMethods/Test1.h"
#include "LuaTestMethods/Test2.h"

#include "LuaTestMethods/ReadNumber.h"
#include "LuaTestMethods/ReadString.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {

	// SECTION: Initial tests with Lua in C++ (structured in classes).
	/**
	Test0 test0;
	Test1 test1;
	Test2 test2;
	/**/
	ReadNumber readNumber;
	ReadString readString;
	/**/

	printf_s("Entering functional method.\n");

	high_resolution_clock::time_point start = high_resolution_clock::now();

	// TestRunner wraps Lua initialization & close code.
	// Open the corresponding .lua file for the Lua code and <subclass of TestMethod>.cpp for the C++ code.
	// Specify a filename to write measurements into.
	// Optionally specify number of samples to repeat the whole test for, and number of runs per each sample (else both are 1).
	// Optionally choose whether to print status/error code after the loadfile.

	// NOTE: Please ensure a directory ALREADY EXISTS, if trying to write a file in a directory.
	// No easy way to create/ensure that within code (~~C++17 adds something, too much effort for a detail here though.)
	
	// SECTION: Final Lua tests (via class instances + TestRunner).
	//TestRunner testRunner("readInCPP_simple_number.lua", "Measures/lua_read_number.txt", readNumber, 64, 1024, false);
	TestRunner testRunner("readInCPP_simple_string.lua", "Measures/lua_read_string.txt", readString, 64, 1024, false);
	/**/

	high_resolution_clock::time_point end = high_resolution_clock::now();

	TestRunner::MeasureTime(start, end, "Complete execution");

	printf_s("Exiting functional method.\n");

	return 0;
}