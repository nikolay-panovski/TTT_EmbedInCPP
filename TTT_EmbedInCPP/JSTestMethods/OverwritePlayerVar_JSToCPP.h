#pragma once

#include "JSTestMethod.h"
#include "../Entities/Player.h"

class OverwritePlayerVar_JSToCPP : public JSTestMethod
{
	private:
		Player* player;

	public:
		OverwritePlayerVar_JSToCPP(Player* pPlayer);
		void Run(duk_context* duk) override;
};