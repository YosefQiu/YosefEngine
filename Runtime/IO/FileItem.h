#pragma once

namespace YOSEF
{
#if YOSEF_ANDROID
#elif YOSEF_EDITOR
	class FileItem
	{
	public:
		char mRelativePath[256];
		__int64 mLastWriteTime;
		static FileItem* Get(const char*path);
	};
#endif
}