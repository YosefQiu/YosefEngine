#pragma once
#include "Runtime/Plugins/Lua/lua.hpp"
#include "Runtime/RuntimePrefix.h"

#define Lua_GetFunction(foo) YOSEF::LuaEngine::PrepareMethod(foo)
#define Lua_PushNil(c) YOSEF::LuaEngine::PushNil(c)
#define Lua_PushUserData(userdata) YOSEF::LuaEngine::PushUserData(userdata)
#define Lua_NewTable() YOSEF::LuaEngine::NewTable()
#define Lua_PushInt(i) YOSEF::LuaEngine::PushInt(i)
#define Lua_PushBoolean(i) YOSEF::LuaEngine::PushBoolean(i)
#define Lua_PushNumber(n) YOSEF::LuaEngine::PushNumber(n)
#define Lua_PushString(str) YOSEF::LuaEngine::PushString(str)
#define Lua_PushLString(str,len) YOSEF::LuaEngine::PushLString(str,len)
#define Lua_Invoke(hint) YOSEF::LuaEngine::Invoke(hint)

namespace YOSEF{
	class LuaEngine{
	public:
		static lua_State*	s_GlobalStatePtr;
		static void Init();
		static lua_State* GetLuaState();
		static void RecycleLuaState(lua_State*L);
		static int CallLibMethod(lua_State*L);
		static void CleanPlugins();
		static lua_State* Store();
		static int Restore();
		static int mCurrentArgCount;
		static bool PrepareMethod(int foo);
		static void PushInt(int a);
		static void PushBoolean(bool a);
		static void PushNumber(double a);
		static void PushString(const char *str);
		static void PushLString(const char *str, int len);
		static void PushNil(int count = 1);
		static void PushUserData(int userdata);
		static void NewTable ();
		static void Invoke(const char * hint);
		static void DumpTable(lua_State*L);
		static int PreloadScript(lua_State*L);
		static bool GetFromCache(lua_State*L, const char*scriptName);
		static bool LoadScriptCode(lua_State*L, const char*scriptName, const char*code, int codeLen);
		static bool GetLoadedTable(lua_State*L, const char *tableName, bool createWhenNotExist = false);
		static bool ExecuteScript(lua_State*L, const char*scriptName, const char*code, int codeLen);
		static bool GetLoadedScript(lua_State*L, const char*scriptName, const char*space=nullptr);
		static bool LoadScriptFromPreloadedBuffers(lua_State*L, const char*scriptName);
		static bool LoadScriptFromUserPath(lua_State*L, const char*scriptName);
		static void UnloadScriptCode(lua_State*L, const char*scriptName);
		static const char*GetLuaPathViaGUID(const char*guid);
	private:
		static int mStackSize;
		static int mTraceBackFoo;
		static std::stack<lua_State*> mStatePool;
		static std::unordered_map<std::string, std::string> mScriptIDToPath;
	};
}
