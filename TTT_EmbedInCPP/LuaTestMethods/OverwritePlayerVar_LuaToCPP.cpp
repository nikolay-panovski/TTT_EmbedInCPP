#include "OverwritePlayerVar_LuaToCPP.h"

void OverwritePlayerVar_LuaToCPP::Run(lua_State* lua) {
	lua_getglobal(lua, "lastLevelSpecialSpawn");

	if (lua_isnumber(lua, -1)) {
		int overwrittenSpawnValue = lua_tonumber(lua, -1);
		player.lastLevelSpecialSpawn = overwrittenSpawnValue;
	}

	lua_pop(lua, 1);
}