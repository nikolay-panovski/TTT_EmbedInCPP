#pragma once

#include "LuaTestMethod.h"
#include "../Entities/Player.h"

class ChangePlayerStats_LuaToCPP : public LuaTestMethod
{
private:
	Player* player;

public:
	ChangePlayerStats_LuaToCPP(Player* pPlayer);
	//static int get_player_hearts(lua_State* lua);	// must be static if class member, credits: https://stackoverflow.com/a/8098460
	void Run(lua_State* lua) override;
};