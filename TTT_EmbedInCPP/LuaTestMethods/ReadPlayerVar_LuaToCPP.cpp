#include "ReadPlayerVar_LuaToCPP.h"

void ReadPlayerVar_LuaToCPP::Run(lua_State* lua) {
	lua_pushinteger(lua, player->lastLevelSpecialSpawn);
	lua_setglobal(lua, "lastLevelSpecialSpawn");
}

ReadPlayerVar_LuaToCPP::ReadPlayerVar_LuaToCPP(Player* pPlayer) {
	player = pPlayer;
}