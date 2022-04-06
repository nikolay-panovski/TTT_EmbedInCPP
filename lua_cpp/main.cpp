#include <lua.hpp>
#include <iostream>
#include <string>

using namespace std;

// TEST 1: HELLO WORLD
/**/
int main() {
	lua_State* lua = luaL_newstate();
	luaL_openlibs(lua);
	int errcode = luaL_loadfile(lua, "helloworld.lua");	// ERROR: if opened from .exe (file explorer OR cmd), error code 6 (suspected ERRFILE)

	printf_s("Error code: %i\n", errcode);

	lua_call(lua, 0, 0);	// lua_call(state, params, returns);

	lua_close(lua);
	return 0;
}
/**/

// TEST 2: SUM A LUA NUMBER AND CPP NUMBER
// + add ability to run from cmd with a number argument (not the cause of the error)
/**
int sumWithLua(int luaNumber, int cppNumber) {
	return luaNumber + cppNumber;
}

int main(int argc, char* argv[]) {
	lua_State* lua = luaL_newstate();
	luaL_openlibs(lua);
	int errcode = luaL_loadfile(lua, "crossglobal.lua");	// NEXT UP: more tests with different .lua files!
															// ERROR: if opened from .exe (file explorer OR cmd), error code 6 (suspected ERRFILE)
	printf_s("Error code: %i\n", errcode);

	lua_call(lua, 0, 0);	// lua_call(state, params, returns);

	lua_getglobal(lua, "num");
	if (lua_isnumber(lua, -1)) {
		int numFromLua = lua_tonumber(lua, -1);
		int result;
		if (argc > 1) {
			result = sumWithLua(numFromLua, std::stoi(argv[1]));	// no error handling if it's not a number at all, yes
		}
		else {
			int numFromCPPDefault = 8;
			result = sumWithLua(numFromLua, numFromCPPDefault);
		}

		printf_s("Result: %i\n", result);
	}

	lua_pop(lua, 1);

	lua_close(lua);
	return 0;
}
/**/