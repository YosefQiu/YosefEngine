#include "Runtime/Scene/GameObject.h"
#include "Runtime/Render/Camera.h"
namespace YOSEF{
	void GameObject::RenderComponentRecursively(Camera*camera, RenderQueue*rq
#if YOSEF_EDITOR
		, DrawCallInfo &rs
#endif
		, bool render_sibling) {
		if (mbEnable && (camera->mCullingFlags&mLayer) != 0) {
			Component*current = mComponents;
			while (current != nullptr) {
				current->Render(rq
#if YOSEF_EDITOR
					, rs
#endif
				);
				current = current->Next<Component>();
			}
		}
		//if parent is disabled,then child is automatically disabled
		if (mbEnable) {
			if (mChild != nullptr) {
				if (mRenderOrder == nullptr){
					Child<GameObject>()->RenderComponentRecursively(camera, rq
#if YOSEF_EDITOR
						, rs
#endif
					);
				}
				else {
				}
			}
		}
		if (render_sibling&&mRightSibling != nullptr){
			RightSibling<GameObject>()->RenderComponentRecursively(camera, rq
#if YOSEF_EDITOR
				, rs
#endif
			);
		}
	}
	void GameObject::RenderShadowMapRecursively(Camera*camera, RenderQueue*rq
#if YOSEF_EDITOR
		, DrawCallInfo &rs
#endif
	) {
		if (mbEnable && (camera->mCullingFlags&mLayer) != 0) {
			Component*current = mComponents;
			while (current != nullptr) {
				current->RenderShadowMap(rq
#if YOSEF_EDITOR
					, rs
#endif
				);
				current = current->Next<Component>();
			}
		}
		//if parent is disabled,then child is automatically disabled
		if (mbEnable) {
			if (mChild != nullptr) {
				Child<GameObject>()->RenderShadowMapRecursively(camera, rq
#if YOSEF_EDITOR
						, rs
#endif
				);
			}
		}
		if (mRightSibling != nullptr) {
			RightSibling<GameObject>()->RenderShadowMapRecursively(camera, rq
#if YOSEF_EDITOR
				, rs
#endif
			);
		}
	}
}