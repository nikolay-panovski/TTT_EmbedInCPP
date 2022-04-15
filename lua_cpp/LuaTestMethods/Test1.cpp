#include "Test1.h"

int Test1::sumWithLua(int luaNumber, int cppNumber) {
	return luaNumber + cppNumber;
}

void Test1::Run(lua_State* lua) {
	lua_getglobal(lua, "num");
	if (lua_isnumber(lua, -1)) {
		int numFromLua = lua_tonumber(lua, -1);
		int result;
		/**
		// MAIN(ARGC, ARGV[]) STUFF - NOT MANDATORY
		if (argc > 1) {
			result = sumWithLua(numFromLua, std::stoi(argv[1]));	// no error handling if it's not a number at all, yes
		}
		else {
			int numFromCPPDefault = 8;
			result = sumWithLua(numFromLua, numFromCPPDefault);
		}
		/**/
		int numFromCPPDefault = 8;
		result = sumWithLua(numFromLua, numFromCPPDefault);

		printf_s("Result: %i\n", result);
	}
	else {
		printf_s("Test is messed up! Check whether the passed in Lua file and test number match!\n");
	}
}