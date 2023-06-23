#pragma once

#include "JSTestMethod.h"
#include "../Entities/Player.h"

class ChangePlayerStats_JSToCPP : public JSTestMethod
{
private:
	Player* player;

public:
	ChangePlayerStats_JSToCPP(Player* pPlayer);
	//static duk_ret_t get_player_hearts(duk_context* duk);
	void Run(duk_context* duk) override;
};