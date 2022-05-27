#pragma once
#include "Runtime/Math/Vector3.h"
#include "Runtime/Base/Component.h"

namespace YOSEF
{
	class AudioListener:public Component
	{
	public:
		AudioListener();
		Vector3f mPos;
		void Update(float deltaTime);
	public:
		DEF_YOSEF_EXPORTED_TYPE_NEW_METHOD(AudioListener,AudioListener)
		DECLEAR_YOSEF_CLASS(AudioListener)
	};
}