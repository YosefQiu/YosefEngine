#pragma once
#include"Runtime/RuntimePrefix.h"

namespace YOSEF
{
	class TouchEvent
	{
	public:
		TouchEvent();
		TouchEvent(float x, float y);
		YOSEFUInt64 mTouchID;
		float mX, mY;
	};

	class IMECharEvent
	{
	public:
		IMECharEvent();
		YOSEFUInt32 mCharCode;
	};

	class MouseWheelEvent {
	public:
		MouseWheelEvent(int key, int delta) {
			mKey = key;
			mWheelDelta = delta;
		}
		int mKey;
		int mWheelDelta;
	};

	class AdInfo {
	public:
		int mRewardVideoStatus;
		int mInterstitialStatus;
		int mBannerStatus;
		AdInfo();
	};
}