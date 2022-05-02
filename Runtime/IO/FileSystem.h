#pragma once
#include "Runtime/RuntimePrefix.h"
#include "YOSEFData.h"
namespace YOSEF
{
	struct FileItemNode
	{
#if YOSEF_PLATFORM_WIN
		TCHAR mName[_MAX_PATH];
#elif YOSEF_IPHONE || YOSEF_ANDROID
		char mName[256];
#endif
		bool mbIsDir;
		__int64 mLastWriteTime;
		std::list<FileItemNode*> mChildren;
		FileItemNode()
		{
#if YOSEF_PLATFORM_WIN
			wmemset(mName, 0, _MAX_PATH);
#elif YOSEF_IPHONE
            memset(mName,0, YOSEF_MAX_PATH_LEN);
#endif
			mbIsDir = false;
		}
		~FileItemNode()
		{
			if (mbIsDir)
			{
				for (std::list<FileItemNode*>::iterator iter=mChildren.begin();iter!=mChildren.end();iter++)
				{
					delete *iter;
				}
			}
		}
	};

	class FileSystem
	{
	public:
#if YOSEF_PLATFORM_WIN
		static void GetFiles(LPCTSTR path, LPCTSTR filter, FileItemNode&root);
		static void GetFiles(LPCTSTR path, LPCTSTR relativeRootPath, LPCTSTR filter, FileItemNode&root);
		static bool DeleteDir(LPCTSTR path);
#endif
		static bool SaveData(const char*filePath,Data&data);
		static YOSEFUInt32 FileSizeOf(const char* path);
		static bool CreateDir(std::string path);
		static bool CreateFile(std::string path);
		static bool MoveFile(const char*srcPath, const char*dstPath);
		static bool DeleteDir(std::string path);
		static bool DeleteFileWithPath(std::string path);
		static bool CopyFile(const char*srcPath,const char*dstPath);
		static bool MoveFileToTrash(const char*path);
		static bool isDirectoryExist(const std::string& dirPath);
		static bool Exists(const char*path);
		static bool isAbsolutePath(const std::string& path);
		static char* LoadFile(const char*path);
		static void CopyDir(const char*src,const char* dst);
		static bool LoadDataFromPath(const char*path,Data&data);
	};
}
