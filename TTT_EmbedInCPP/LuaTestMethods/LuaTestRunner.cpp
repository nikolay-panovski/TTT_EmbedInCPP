//#define MEASURE_RUN
#define MEASURE_SAMPLE
//#define MEASURE_DEBUG_PRINT

#pragma once

//#include <Windows.h>
//#include <Psapi.h>

#include "LuaTestRunner.h"

LuaTestRunner::LuaTestRunner(const char* luaFilename, const char* measureStoreFilename,
					   LuaTestMethod& runMethod, int sampleCount, int runsPerSample, bool printError) {
	this->lua = luaL_newstate();
	luaL_openlibs(lua);

	if (printError) {
		if (luaL_loadfile(lua, luaFilename) != LUA_OK) {
			printf_s("Error code: %s\n", lua_tostring(lua, -1));

			// TODO in good code: throw and handle an exception (god bless StackOverflow)
			// else runMethod.Run below will throw an exception
		}
		else {
			printf_s("LUA_OK: Lua file loaded fine.\n");
		}
	}
	else {
		luaL_loadfile(lua, luaFilename);
	}

	lua_call(lua, 0, 0);	// lua_call(state, params, returns);

	RunWithMeasurements(measureStoreFilename, runMethod, sampleCount, runsPerSample);

	lua_pop(lua, 1);

	lua_close(lua);
}

void LuaTestRunner::RunWithMeasurements(const char* fileToWriteIn,
									 LuaTestMethod& runMethod, int sampleCount, int runsPerSample) {
	std::ofstream sampleTimeWriter;
	sampleTimeWriter.open(fileToWriteIn);

	sampleTimeWriter << "Sample,Time" << "\n";
	for (int i = 1; i <= sampleCount; i++) {
		high_resolution_clock::time_point sampleStart = high_resolution_clock::now();
		for (int i = 1; i <= runsPerSample; i++) {
			#ifdef MEASURE_RUN
			high_resolution_clock::time_point runStart = high_resolution_clock::now();
			runMethod.Run(lua);
			high_resolution_clock::time_point runEnd = high_resolution_clock::now();
			LuaTestRunner::MeasureTime(runStart, runEnd, "\t\tRun");	// string in simple form to avoid throttle via many string conversions
			#else
			runMethod.Run(lua);
			#endif
		}

		high_resolution_clock::time_point sampleEnd = high_resolution_clock::now();

		#ifdef MEASURE_SAMPLE
		long long sampleTime = LuaTestRunner::MeasureTime(sampleStart, sampleEnd, "\tSample");

		//PROCESS_MEMORY_COUNTERS counters;
		//GetProcessMemoryInfo(GetCurrentProcess(), &counters, sizeof(counters));

		sampleTimeWriter << i << "," << sampleTime /* << "," << counters.WorkingSetSize*/ << "\n";
		#endif
	}

	sampleTimeWriter.close();
}

long long LuaTestRunner::MeasureTime(high_resolution_clock::time_point start, high_resolution_clock::time_point end, std::string scope) {
	nanoseconds time_span_nano = duration_cast<nanoseconds>(end - start);
	microseconds time_span_micro = duration_cast<microseconds>(end - start);
	milliseconds time_span_milli = duration_cast<milliseconds>(end - start);
	seconds time_span_seconds = duration_cast<seconds>(end - start);
	#ifdef MEASURE_DEBUG_PRINT
	printf_s("%s took %I64i nanoseconds.\n", scope.c_str(), time_span_nano.count());
	printf_s("%s took %I64i microseconds.\n", scope.c_str(), time_span_micro.count());
	printf_s("            aka %I64i milliseconds.\n", time_span_milli.count());
	printf_s("            aka %I64i seconds.\n", time_span_seconds.count());
	#endif

	return time_span_nano.count();
}

LuaTestRunner::~LuaTestRunner() {
	printf_s("TestRunner destroyed. Tests ending. \n");
}