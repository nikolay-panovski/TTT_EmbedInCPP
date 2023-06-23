#include "OverwritePlayerVar_JSToCPP.h"

void OverwritePlayerVar_JSToCPP::Run(duk_context* duk) {
	duk_get_prop_string(duk, -1, "lastLevelSpecialSpawn");

	if (duk_check_type(duk, -1, DUK_TYPE_NUMBER)) {
		int overwrittenSpawnValue = duk_to_number(duk, -1);
		player->lastLevelSpecialSpawn = overwrittenSpawnValue;
	}

	duk_pop(duk);
}

OverwritePlayerVar_JSToCPP::OverwritePlayerVar_JSToCPP(Player* pPlayer) {
	player = pPlayer;
}