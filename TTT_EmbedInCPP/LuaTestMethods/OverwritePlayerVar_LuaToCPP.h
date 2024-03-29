#pragma once

#include "LuaTestMethod.h"
#include "../Entities/Player.h"

class OverwritePlayerVar_LuaToCPP : public LuaTestMethod
{
	private:
		Player* player;

	public:
		OverwritePlayerVar_LuaToCPP(Player* pPlayer);
		void Run(lua_State* lua) override;
};