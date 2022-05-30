#pragma once
#include "Runtime/Base/Component.h"
#include "Runtime/Render/YOSEFGL.h"
#include "Runtime/Render/Camera.h"
namespace YOSEF
{
	struct RenderingParam
	{
		float*mViewMatrix;
		float*mProjectionMatrix;
	};
	class CustomComponent :public Component
	{
	public:
		void Update(float deltaTime);
		void Render(RenderQueue*rq
#if YOSEF_EDITOR
			, DrawCallInfo &rs
#endif
		);
		void Rendering(Camera*camera);
		CustomComponent();
		virtual ~CustomComponent();
	public:
		SmartPtr<Material> mMaterial;
		int mRenderingParam;
		int mUpdater;
		int mRenderer;
	public:
		DECLEAR_YOSEF_CLASS(CustomComponent)
	};
}