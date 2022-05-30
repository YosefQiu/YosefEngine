#include "RenderOrder.h"
namespace YOSEF{
	RenderOrder::RenderOrder():mRenderUnit(nullptr){
	}
	RenderOrder::~RenderOrder(){
	}
	void RenderOrder::Update(float deltaTime){
	}
	void RenderOrder::Render(RenderQueue*rq
#if YOSEF_EDITOR
		, DrawCallInfo &rs
#endif
	){
	}
}
