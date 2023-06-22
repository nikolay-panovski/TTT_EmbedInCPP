#pragma once

#include <lua.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include <chrono>

#include "LuaTestMethod.h"

using namespace std::chrono;

class LuaTestRunner
{
	private:
		lua_State* lua;

	private:
		void RunWithMeasurements(const char* fileToWriteIn, 
								 LuaTestMethod& runMethod, int sampleCount = 1, int runsPerSample = 1);

	public: 
		LuaTestRunner(const char* luaFilename, const char* measureStoreFilename, 
				   LuaTestMethod& runMethod, int sampleCount = 1, int runsPerSample = 1, bool printError = true);
		~LuaTestRunner();

		// Measure time in different units and return a measurement (default is milliseconds).
		static long long MeasureTime(high_resolution_clock::time_point start, high_resolution_clock::time_point end, std::string scope = "");
};

