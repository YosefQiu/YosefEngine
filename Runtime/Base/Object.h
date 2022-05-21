#pragma once
#include "Runtime/RuntimePrefix.h"
#include "Runtime/LuaEngine/LuaEngine.h"
#define DEFINE_TYPE_ID(T,ID) const int TYPEID_##T=ID;
#define YOSEF_TYPE_ID(T) TYPEID_##T
#include "ClassID.h"
#define DECLEAR_YOSEF_CLASS(T) \
virtual int GetClassID(){return YOSEF_TYPE_ID(T);}\
static int API_ClassID(lua_State*L){lua_pushinteger(L,YOSEF_TYPE_ID(T));return 1;} \
static const int ClassID=YOSEF_TYPE_ID(T); \
static const char* GetTypeName(){return #T;} \
static bool Is##T(lua_State*L,int index) { \
	YOSEF::LuaEngine::Store(); \
	if(Object::IsValid(L,index)) \
	{ \
		lua_getfield(L, index, "ClassID"); \
		if(lua_isfunction(L,-1))\
		{\
			lua_pcall(L, 0, 1, 0); \
			int classID=lua_tointeger(L,-1);\
			if(classID==ClassID)\
			{\
				YOSEF::LuaEngine::Restore();\
				return true;\
			}\
			else\
			{\
				YOSEF::LuaEngine::Restore();\
				return false;\
			}\
		}\
		else\
		{\
			YOSEF::LuaEngine::Restore();\
			return false;\
		}\
	}\
	else\
	{\
		YOSEF::LuaEngine::Restore();\
		return false;\
	}\
	YOSEF::LuaEngine::Restore();\
	return false;\
}
#define CreateLuaDataViaExistObject(ptr,T,L) \
do\
{\
T**pp = (T**)lua_newuserdata(L, sizeof(T*));\
*pp=ptr;\
SET_LUA_TYPE(L, T);\
ptr->mLuaData = luaL_ref(L, LUA_REGISTRYINDEX);\
}while(0)
namespace YOSEF {
	class Object {
	public:
		Object(int autorelease = 1);
		virtual ~Object();
	public:
		YOSEFSInt32 mReferenceCount;
		int mLuaData;
		int mObjectMask;
	public:
		void retain();
		void release();
	public:
		void GetUserData(lua_State* L);
		void PushUserData(lua_State* L) {
			if (mLuaData != LUA_REFNIL) {
				lua_getref(L, mLuaData);
			}
			else {
				lua_pushnil(L);
			}
		}
		template<typename T>
		T* CreateExportedYOSEFType() {
			lua_State* L = LuaEngine::Store();
			T::New_ExportedYOSEFType(L);
			T* pObject = (*(T**)lua_touserdata(L, -1));
			LuaEngine::Restore();
			return pObject;
		}
		static int DefaultGC(lua_State* L);
		static bool IsValid(lua_State* L, int index);
		DECLEAR_YOSEF_CLASS(Object)
	};
}