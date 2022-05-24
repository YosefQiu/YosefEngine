#include "YosefFloat.h"
bool IsFinite(const float& value) {
	// Returns false if value is NaN or +/- infinity
	YOSEFUInt32 intval = *reinterpret_cast<const YOSEFUInt32*>(&value);
	return (intval & 0x7f800000) != 0x7f800000;
}
bool IsFinite(const double& value) {
	// Returns false if value is NaN or +/- infinity
	YOSEFUInt64 intval = *reinterpret_cast<const YOSEFUInt64*>(&value);
	return (intval & 0x7ff0000000000000LL) != 0x7ff0000000000000LL;
}
namespace YOSEF {
	bool EqualApproximately(float f0, float f1, float epsilon /* = 0.000001f */) {
		float dist = (f0 - f1);
		dist = YOSEF_ABS(dist);
		return dist <= epsilon;
	}
	int FloorfToInt(float f) {
		return f >= 0 ? (int)f : (int)(f - sBiggestFloatSmallerThanOne);
	}
	float LinearInterpolate(float from, float to, float t) {
		return to * t + from * (1.0f - t);
	}
	float CopySignf(float x, float y){
		union{
			float f;
			YOSEFUInt32 i;
		} u, u0, u1;
		u0.f = x; u1.f = y;
		YOSEFUInt32 a = u0.i;
		YOSEFUInt32 b = u1.i;
		YOSEFSInt32 mask = 1 << 31;
		YOSEFUInt32 sign = b & mask;
		a &= ~mask;
		a |= sign;
		u.i = a;
		return u.f;
	}
}