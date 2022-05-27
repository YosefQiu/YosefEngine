#pragma once
#include "Runtime/RuntimePrefix.h"
namespace YOSEF{
	class IndexBuffer
	{
	public:
		IndexBuffer(YOSEFUInt16 size=0);
        ~IndexBuffer();
		YOSEFSInt32 mSize;
		YOSEFSInt32 mBufferSize;
		YOSEFUInt16 *mIndexes;
		void Init(YOSEFUInt16 size);
	};
}
