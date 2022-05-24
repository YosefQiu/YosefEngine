#pragma once
#include "Runtime/RuntimePrefix.h"
#include "Color.h"

namespace YOSEF
{
	class ColorHSB
	{
	public:
		ColorHSB(YOSEFUInt8 r,YOSEFUInt8 g,YOSEFUInt8 b);
		ColorHSB(Color4B&color);
		ColorHSB();
		YOSEFUInt16 h, s, b;
		void ToRGB(Color4B&color);
	};
}