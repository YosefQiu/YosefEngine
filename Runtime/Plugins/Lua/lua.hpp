#pragma once
extern "C"
{
#include "External/Lua/LuaVMLib/lua.h"
#include "External/Lua/LuaVMLib/lualib.h"
#include "External/Lua/LuaVMLib/lauxlib.h"
}
#define TO_USERDATA(L,t,idx) (*(t**)lua_touserdata(L,idx))