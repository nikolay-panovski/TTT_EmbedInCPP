#include "TestRunner.h"

TestRunner::TestRunner(const char* filename, TestMethod& runMethod, bool printError) {
	this->lua = luaL_newstate();
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

	runMethod.Run(lua);

	lua_pop(lua, 1);

	lua_close(lua);
}

TestRunner::~TestRunner() {
	printf_s("TestRunner destroyed. Tests ending. \n");
}