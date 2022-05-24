#pragma once
#include "Runtime/Utils/LinkedList.h"
#include "Runtime/RuntimePrefix.h"
#include "Runtime/Render/YosefGL.h"

namespace YOSEF{
	class Attribute :public LinkedList{
	public:
		Attribute();
		~Attribute();
		void Enable();
		YOSEFSInt32 mAttributeSlot;
		YOSEFSInt32 mDataOffSet;
		GLenum mDataType;
		YOSEFUInt8 mUnitCount;
		GLboolean mNormalized;
		YOSEFUInt16 mDataStride;
	};
}