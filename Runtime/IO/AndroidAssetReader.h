#pragma once
#include "Runtime/RuntimePrefix.h"
#if YOSEF_ANDROID
#include "YOSEFData.h"
#include "Runtime/Plugins/Lua/lua.hpp"
namespace YOSEF{
	class AndroidAssetReader{
	public:
		static bool LoadInternalData(const char*path,Data &data);
		static void GetItemListInDirectory(lua_State*L, const char * path);
		static bool DeleteDir(const char *path);
		static bool DeleteFileWithPath(const char *path);
		static AAssetManager*sAssetManager;
	};
}
#endif