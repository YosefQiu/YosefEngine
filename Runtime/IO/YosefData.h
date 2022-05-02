#pragma once
#include "Runtime/RuntimePrefix.h"
namespace YOSEF
{
	class Data
	{
	public:
		Data(int buffer_size=0);
		virtual ~Data();
		void Reset();
		void SetBufferSize(int bufferSize);
		void MakeZero();
		YOSEFUInt8* mData;
		YOSEFSInt32 mDataLen;
		YOSEFSInt32 mBufferSize;
	};
}