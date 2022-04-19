#include "ReadNumber.h"

void ReadNumber::Run(lua_State* lua) {
	lua_getglobal(lua, "readVar");

	if (lua_isnumber(lua, -1)) {
		int numFromLua = lua_tonumber(lua, -1);
		//printf_s("Number: %i\n", numFromLua);		// do NOT print in actual performance tests.
	}

	lua_pop(lua, 1);
}