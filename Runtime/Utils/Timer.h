#pragma once
#include "Runtime/RuntimePrefix.h"
#include "Runtime/Base/Object.h"
#include "Runtime/NetWork/SocketUtils.h"
#ifdef YOSEF_PLATFORM_WIN
//sleep for ms
#define YOSEFSleep(ms) Sleep(ms)
#elif YOSEF_PLATFORM_UNIX
#include <sys/time.h>
#define YOSEFSleep(ms) CanRead(0,0,ms)
#endif

namespace YOSEF{
	class Timer : public Object{
	public:
		Timer();
		void Start();
		float GetTimeInMs() const;
		YOSEFUInt64 GetTimeInMsi();
		void Reset();
	private:
#ifdef YOSEF_PLATFORM_WIN
		__int64 GetTime() const;
		void* m_threadHandle;
		unsigned long m_processAffinityMask;
		__int64 m_startTime;
		__int64 m_frequency;
#elif YOSEF_PLATFORM_UNIX
        timeval mStartTime;
        YOSEFUInt64 mStartTimeInMS;
#endif
	};
}
