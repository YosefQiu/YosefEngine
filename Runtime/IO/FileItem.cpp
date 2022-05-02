#include "FileItem.h"
#include "Runtime/String/StringUtils.h"

#if YOSEF_EDITOR
#include <io.h>
#endif

#if YOSEF_ANDROID
#elif YOSEF_EDITOR
namespace YOSEF
{
	FileItem*FileItem::Get(const char*path)
	{
		FileItem*item = nullptr;
#if YOSEF_EDITOR
		_finddata_t fileinfo;
		long hFile = _findfirst(path, &fileinfo);
		if (hFile)
		{
			item = new (kMemEditorId)FileItem;
			memset(item->mRelativePath, 0, 256);
			strcpy(item->mRelativePath, path);
			item->mLastWriteTime=fileinfo.time_write;
		}
		_findclose(hFile);
#else
#endif
		return item;
	}
}
#endif
