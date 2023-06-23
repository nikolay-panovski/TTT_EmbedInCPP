#pragma once

#pragma once

#include "LuaTestMethod.h"
#include "../Entities/ItemStorage.h"
#include "../Entities/Item.h"

class InsertItem_LuaToCPP : public LuaTestMethod
{
	private:
		ItemStorage* items;
	
	public:
		InsertItem_LuaToCPP(ItemStorage* pItems);
		void Run(lua_State* lua) override;
};