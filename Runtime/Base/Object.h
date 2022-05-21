#pragma once
#include "Runtime/RuntimePrefix.h"

namespace YOSEF 
{
	class Object 
	{
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
	};
}