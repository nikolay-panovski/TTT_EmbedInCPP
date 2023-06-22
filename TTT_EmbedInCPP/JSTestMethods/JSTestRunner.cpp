#include "JSTestRunner.h"

/* https://github.com/svaarala/duktape/blob/master/examples/guide/processlines.c
 * Helper function to process .js input files (not included in default Duktape for minimalism, not yet included in extras).
 * "For brevity assumes a maximum file length of 16kB."
 */
static void push_file_as_string(duk_context* ctx, const char* filename) {
	FILE* f;
	size_t len;
	char buf[16384];

	f = fopen(filename, "rb");
	if (f) {
		len = fread((void*)buf, 1, sizeof(buf), f);
		fclose(f);
		duk_push_lstring(ctx, (const char*)buf, (duk_size_t)len);
	}
	else {
		duk_push_undefined(ctx);
	}
}


JSTestRunner::JSTestRunner(const char* JSFilename, const char* measureStoreFilename,
	TestMethod& runMethod, int sampleCount, int runsPerSample, bool printError) {
	this->duk = duk_create_heap_default();

	if (!duk) {
		printf_s("Error on Duktape context init. Exiting program!");
		exit(1);
	}

	// load entire file as a global object with properties = {vars, functions}:
	push_file_as_string(duk, JSFilename);
	if (printError) {
		if (duk_peval(duk) != 0) {
			printf_s("Error running: %s\nAborting program!", duk_safe_to_string(duk, -1));
			duk_destroy_heap(duk);
			exit(1);
		}
		else {
			printf_s("Duktape Eval: JS file loaded fine.\n");
		}
	}
	else {
		duk_peval(duk);
	}
	
	// push the eval'd file contents as a global object - later "get_prop" calls will refer to it on the stack:
	duk_push_global_object(duk);

	RunWithMeasurements(measureStoreFilename, runMethod, sampleCount, runsPerSample);

	duk_pop(duk);

	duk_destroy_heap(duk);
}

void JSTestRunner::RunWithMeasurements(const char* fileToWriteIn,
	TestMethod& runMethod, int sampleCount, int runsPerSample) {
	std::ofstream sampleTimeWriter;
	sampleTimeWriter.open(fileToWriteIn);

	for (int i = 1; i <= sampleCount; i++) {
		high_resolution_clock::time_point sampleStart = high_resolution_clock::now();

		for (int i = 1; i <= runsPerSample; i++) {
			high_resolution_clock::time_point runStart = high_resolution_clock::now();
			runMethod.Run(duk);
			high_resolution_clock::time_point runEnd = high_resolution_clock::now();
			JSTestRunner::MeasureTime(runStart, runEnd, "\t\tRun");	// string in simple form to avoid throttle via many string conversions
		}

		high_resolution_clock::time_point sampleEnd = high_resolution_clock::now();
		long long sampleTime = JSTestRunner::MeasureTime(sampleStart, sampleEnd, "\tSample");

		// TODO: Export (write to file) time info from runs/samples automatically
		sampleTimeWriter << "Sample " << i << " time: " << sampleTime << " milliseconds" << "\n";
	}

	sampleTimeWriter.close();
}

long long JSTestRunner::MeasureTime(high_resolution_clock::time_point start, high_resolution_clock::time_point end, std::string scope) {
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

JSTestRunner::~JSTestRunner() {
	printf_s("TestRunner destroyed. Tests ending. \n");
}