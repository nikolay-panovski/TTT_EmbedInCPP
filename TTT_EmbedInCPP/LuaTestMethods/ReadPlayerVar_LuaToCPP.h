#pragma once

#include "LuaTestMethod.h"
#include "../Entities/Player.h"

class ReadPlayerVar_LuaToCPP : public LuaTestMethod
{
private:
	Player* player;

public:
	ReadPlayerVar_LuaToCPP(Player* pPlayer);
	void Run(lua_State* lua) override;
};