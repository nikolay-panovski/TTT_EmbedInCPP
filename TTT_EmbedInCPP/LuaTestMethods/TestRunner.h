#pragma once

#include <lua.hpp>
#include <iostream>
#include <string>

#include <chrono>

#include "TestMethod.h"

using namespace std::chrono;

class TestRunner
{
	private:
		lua_State* lua;

	private:
		void RunWithMeasurements(TestMethod& runMethod, int sampleCount = 1, int runsPerSample = 1);

	public: 
		TestRunner(const char* filename, TestMethod& runMethod, int sampleCount = 1, int runsPerSample = 1, bool printError = true);
		~TestRunner();

		static void MeasureTime(high_resolution_clock::time_point start, high_resolution_clock::time_point end, std::string scope = "");
};

