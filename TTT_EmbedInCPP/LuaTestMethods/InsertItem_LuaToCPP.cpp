#include "InsertItem_LuaToCPP.h"

void InsertItem_LuaToCPP::Run(lua_State* lua) {
	lua_getglobal(lua, "SampleItem");
	lua_getfield(lua, -1, "charge");
	lua_getfield(lua, -2, "price");
	lua_getfield(lua, -3, "ItemEffect");
	int charge = lua_tonumber(lua, -1);
	int price = lua_tonumber(lua, -1);
	//Item(charge, price, lua_topointer(lua, -1));
	lua_pop(lua, 1);
}

InsertItem_LuaToCPP::InsertItem_LuaToCPP(ItemStorage* pItems) {
	items = pItems;
}