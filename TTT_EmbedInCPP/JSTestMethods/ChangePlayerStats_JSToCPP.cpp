#include "ChangePlayerStats_JSToCPP.h"

/**
duk_ret_t ChangePlayerStats_JSToCPP::get_player_hearts(duk_context* duk) {
	duk_push_int(duk, player->GetHearts());
	return 1;
}
/**/

void ChangePlayerStats_JSToCPP::Run(duk_context* duk) {
	//duk_push_c_function(duk, get_player_hearts, 0);
	duk_get_prop_string(duk, -1, "CalcDamage");
	duk_push_int(duk, player->GetHearts());
	duk_call(duk, 1);	// call from the "duk" stack with 1 arg
	player->AddDamage(duk_to_int(duk, -1));	// right after the call the return value will be a number
	duk_pop(duk);
}

ChangePlayerStats_JSToCPP::ChangePlayerStats_JSToCPP(Player* pPlayer) {
	player = pPlayer;
}