#include "ChangePlayerStats_LuaToCPP.h"

/**
int ChangePlayerStats_LuaToCPP::get_player_hearts(lua_State* lua) {
	lua_pushinteger(lua, player->GetHearts());
	return 1;
}
/**/

void ChangePlayerStats_LuaToCPP::Run(lua_State* lua) {
	//lua_pushcfunction(lua, get_player_hearts);
	lua_getglobal(lua, "CalcDamage");
	lua_pushinteger(lua, player->GetHearts());
	lua_call(lua, 1, 1);	// call from the "lua" stack with 1 arg (hearts) and 1 return (damage)
	player->AddDamage(lua_tonumber(lua, -1));	// right after the call the return value will be a number
	lua_pop(lua, 1);
}

ChangePlayerStats_LuaToCPP::ChangePlayerStats_LuaToCPP(Player* pPlayer) {
	player = pPlayer;
}