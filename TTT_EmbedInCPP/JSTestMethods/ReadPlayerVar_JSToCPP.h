#pragma once

#include "JSTestMethod.h"
#include "../Entities/Player.h"

class ReadPlayerVar_JSToCPP : public JSTestMethod
{
private:
	Player* player;

public:
	ReadPlayerVar_JSToCPP(Player* pPlayer);
	void Run(duk_context* duk) override;
};