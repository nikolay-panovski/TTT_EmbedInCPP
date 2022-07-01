#include "TestRunner.h"

TestRunner::TestRunner(const char* luaFilename, const char* measureStoreFilename,
					   TestMethod& runMethod, int sampleCount, int runsPerSample, bool printError) {
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

void TestRunner::RunWithMeasurements(const char* fileToWriteIn,
									 TestMethod& runMethod, int sampleCount, int runsPerSample) {
	std::ofstream sampleTimeWriter;
	sampleTimeWriter.open(fileToWriteIn);

	for (int i = 1; i <= sampleCount; i++) {
		high_resolution_clock::time_point sampleStart = high_resolution_clock::now();

		for (int i = 1; i <= runsPerSample; i++) {
			high_resolution_clock::time_point runStart = high_resolution_clock::now();
			runMethod.Run(lua);
			high_resolution_clock::time_point runEnd = high_resolution_clock::now();
			TestRunner::MeasureTime(runStart, runEnd, "\t\tRun");	// string in simple form to avoid throttle via many string conversions
		}

		high_resolution_clock::time_point sampleEnd = high_resolution_clock::now();
		long long sampleTime = TestRunner::MeasureTime(sampleStart, sampleEnd, "\tSample");

		// TODO: Export (write to file) time info from runs/samples automatically
		sampleTimeWriter << "Sample "  << i << " time: " << sampleTime << " milliseconds" << "\n";
	}

	sampleTimeWriter.close();
}

long long TestRunner::MeasureTime(high_resolution_clock::time_point start, high_resolution_clock::time_point end, std::string scope) {
	nanoseconds time_span_nano = duration_cast<nanoseconds>(end - start);
	microseconds time_span_micro = duration_cast<microseconds>(end - start);
	milliseconds time_span_milli = duration_cast<milliseconds>(end - start);
	seconds time_span_seconds = duration_cast<seconds>(end - start);
	printf_s("%s took %I64i nanoseconds.\n", scope.c_str(), time_span_nano.count());
	printf_s("%s took %I64i microseconds.\n", scope.c_str(), time_span_micro.count());
	printf_s("            aka %I64i milliseconds.\n", time_span_milli.count());
	printf_s("            aka %I64i seconds.\n", time_span_seconds.count());

	return time_span_milli.count();
}

TestRunner::~TestRunner() {
	printf_s("TestRunner destroyed. Tests ending. \n");
}