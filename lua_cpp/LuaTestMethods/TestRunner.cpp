#include "TestRunner.h"

TestRunner::TestRunner(const char* filename, TestMethod& runMethod, bool printError) {
	this->lua = luaL_newstate();
	luaL_openlibs(lua);

	if (printError) {
		int errcode = luaL_loadfile(lua, filename);

		printf_s("Error code: %i\n", errcode);
	}
	else {
		luaL_loadfile(lua, filename);
	}

	lua_call(lua, 0, 0);	// lua_call(state, params, returns);

	runMethod.Run(lua);

	lua_pop(lua, 1);

	lua_close(lua);
}

TestRunner::~TestRunner() {

}