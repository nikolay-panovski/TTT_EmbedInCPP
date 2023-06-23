#include "ReadPlayerVar_JSToCPP.h"

void ReadPlayerVar_JSToCPP::Run(duk_context* duk) {
	duk_push_number(duk, player->lastLevelSpecialSpawn);
	duk_put_prop_string(duk, -2, "lastLevelSpecialSpawn");
}

ReadPlayerVar_JSToCPP::ReadPlayerVar_JSToCPP(Player* pPlayer) {
	player = pPlayer;
}