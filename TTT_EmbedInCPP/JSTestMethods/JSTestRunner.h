#pragma once

#include <duktape.h>
#include <fstream>
#include <iostream>
#include <string>

#include <chrono>

#include "TestMethod.h"

using namespace std::chrono;

class JSTestRunner
{
private:
	duk_context* duk;

private:
	void RunWithMeasurements(const char* fileToWriteIn,
		TestMethod& runMethod, int sampleCount = 1, int runsPerSample = 1);

public:
	JSTestRunner(const char* JSFilename, const char* measureStoreFilename,
		TestMethod& runMethod, int sampleCount = 1, int runsPerSample = 1, bool printError = true);
	~JSTestRunner();

	// Measure time in different units and return a measurement (default is milliseconds).
	static long long MeasureTime(high_resolution_clock::time_point start, high_resolution_clock::time_point end, std::string scope = "");
};

