#include "Test2.h"

void Test2::Run(lua_State* lua) {
	/** Lua side: (contiguous) Array with 100 values, each being the square of its index.
	*   C++ side: Get values one by one and print them, without print()ing from Lua.
	*/

	lua_getglobal(lua, "array");

	int count = 1;
	lua_geti(lua, -1, count);
	while (lua_isnil(lua, -1) == 0)
	{
		/**
		lua_getglobal(lua, "isThisNil");	// returns a TYPE
		int isNil = lua_isnil(lua, -1);		// this line NOT to be confused with lua_isnil(lua, lua_getglobal(lua, "isThisNil")); !!
		printf_s("%i \n", isNil);
		lua_pop(lua, 1);
		/**/

		int nextArrayValue = lua_tonumber(lua, -1);
		printf_s("Value at index %i = %i\n", count, nextArrayValue);

		lua_pop(lua, 1);	// pop top element of the stack, which after the lua_geti is the retrieved number (or nil)

		count++;
		lua_geti(lua, -1, count);
	}
}