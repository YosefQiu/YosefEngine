#pragma once
#define _00000000_00000000_00000000_00000001 1
#define _00000000_00000000_00000000_00000010 2
#define _00000000_00000000_00000000_00000100 4
#define _00000000_00000000_00000000_00001000 8
#define _00000000_00000000_00000000_00010000 16
#define _00000000_00000000_00000000_00100000 32
#define _00000000_00000000_00000000_01000000 64
#define _00000000_00000000_00000000_10000000 128
#define _00000000_00000000_00000001_00000000 256
#define _00000000_00000000_00000010_00000000 512
#define _00000000_00000000_00000100_00000000 1024
#define _00000000_00000000_00001000_00000000 2048
#define _00000000_00000000_00010000_00000000 4096
#define _00000000_00000000_00100000_00000000 8192
#define _00000000_00000000_01000000_00000000 16384
#define _00000000_00000000_10000000_00000000 32768
#define YOSEF_DEPRECATED __declspec(deprecated)
typedef signed char						YOSEFSInt8;
typedef unsigned char					YOSEFUInt8;
typedef YOSEFUInt8						YOSEFUByte;
typedef YOSEFSInt8						YOSEFByte;
typedef signed short					YOSEFSInt16;
typedef unsigned short					YOSEFUInt16;
typedef int								YOSEFSInt32;
typedef unsigned int					YOSEFUInt32;
typedef unsigned long long				YOSEFUInt64;
typedef signed long long				YOSEFSInt64;
typedef YOSEFSInt32						LuaScriptHandle;
typedef void*							YOSEFAny;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <list>
#include <fstream>

#include <unordered_map>
#include <unordered_set>

#define YOSEF_MAX_PATH_LEN 256
#define RELEASE (!_DEBUG)
#if YOSEF_EDITOR || YOSEF_WIN_PLAYER
#define YOSEF_PLATFORM_WIN 1
#include <WinSock2.h>
#include <windows.h>
#include <dwmapi.h>
#include <gdiplus.h>
#include <ShlObj.h>
#include <WinNls.h>
#include <wchar.h>
#include <tchar.h>
#include <io.h>
#include <direct.h>
#include <ShObjIdl.h>
#include <shellapi.h>
#include <ObjBase.h>
using namespace Gdiplus;
#define NOMINMAX
#include <time.h>
#elif YOSEF_IPHONE || YOSEF_ANDROID || YOSEF_OSX_PLAYER
#define YOSEF_PLATFORM_UNIX 1
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <net/if.h>
#include <pthread.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#ifdef YOSEF_IPHONE
#include <ifaddrs.h>
#endif // YOSEF_IPHONE
#ifdef YOSEF_ANDROID
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <android/native_window_jni.h>
#include <dirent.h>
#include <sys/stat.h>
#define JAVA_API(return_type) extern "C" JNIEXPORT return_type JNICALL
#define JFOO(CLS,METHOD) Java_com_YOSEF_battlefire_androidplayer_##CLS##_##METHOD
#endif // YOSEF_ANDROID
typedef int64_t __int64;
#endif
#if YOSEF_PLATFORM_WIN
#define YOSEF_STRICMP _stricmp 
#else 
#define YOSEF_STRICMP strcasecmp
#endif
#if YOSEF_EDITOR && _DEBUG
#define OPT(return_type) virtual return_type
#else
#define OPT(return_type) return_type
#endif

