#pragma once
#include "Runtime/Base/Component.h"
namespace YOSEF{
	class RenderUnit :public DoubleLinkedList {
	public:
		GameObject*mGameObject;
		int mIndex;
		int mOffset;
	};
	class RenderOrder :public Component {
	public:
		RenderOrder();
		virtual ~RenderOrder();
		virtual void Update(float deltaTime);
		virtual void Render(RenderQueue*rq
#if YOSEF_EDITOR
			, DrawCallInfo &rs
#endif
		);
	public:
		RenderUnit*mRenderUnit;
	public:
		DECLEAR_YOSEF_CLASS(RenderOrder)
	};
}