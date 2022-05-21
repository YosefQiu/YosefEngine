#pragma once
#include "Runtime/Base/Object.h"
#if YOSEF_PLATFORM_WIN
const int GUIDStringLength = 32;
namespace YOSEF 
{
	struct GUID 
	{
		YOSEFUInt32 mData[4];
		GUID(YOSEFUInt32 a, YOSEFUInt32 b, YOSEFUInt32 c, YOSEFUInt32 d) {
			mData[0] = a; 
			mData[1] = b;
			mData[2] = c;
			mData[3] = d;
		}
		GUID() 
		{ 
			mData[0] = 0; 
			mData[1] = 0; 
			mData[2] = 0; 
			mData[3] = 0; 
		}
		bool operator == (const GUID& r) const 
		{
			return mData[0] == r.mData[0] && mData[1] == r.mData[1] && mData[2] == r.mData[2] && mData[3] == r.mData[3];
		}
		bool operator != (const GUID& r) const { return !(*this == r); }
		bool operator < (const GUID& r) const { return CompareGUID(*this, r) == -1; }
		friend int CompareGUID(const GUID& l, const GUID& r);
		bool IsValid() const { return mData[0] != 0 || mData[1] != 0 || mData[2] != 0 || mData[3] != 0; }
		void Init();
		void GetStringGUID(char*out);
	};
	std::string GUIDToString(const GUID& guid);
	void GUIDToString(const GUID& guid, char* string);
	YOSEF::GUID StringToGUID(const std::string& guidString);
	YOSEF::GUID StringToGUID(const char* guidString, size_t stringLength);
	inline int CompareGUID(const YOSEF::GUID& l, const YOSEF::GUID& r) 
	{
		for (int i = 0; i < 4; i++) 
		{
			if (l.mData[i] < r.mData[i])
				return -1;
			if (l.mData[i] > r.mData[i])
				return 1;
		}
		return 0;
	}
	bool CompareGUIDStringLess(const YOSEF::GUID& l, const YOSEF::GUID& r);
}
#endif