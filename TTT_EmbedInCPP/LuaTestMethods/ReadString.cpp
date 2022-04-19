#include "ReadString.h"

void ReadString::Run(lua_State* lua) {
	lua_getglobal(lua, "readVar");

	if (lua_isstring(lua, -1)) {
		std::string stringFromLua = lua_tostring(lua, -1);
	}

	lua_pop(lua, 1);
}