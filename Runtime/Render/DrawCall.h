#pragma once
#include "Runtime/Utils/SmartPtr.h"
#include "Runtime/Utils/LinkedList.h"
#include "YosefGL.h"
#include "Runtime/Render/GL20/VBO.h"
#include "Runtime/Render/GL20/EBO.h"
namespace YOSEF{
	class Camera;
	class CustomComponent;
	class RenderPass;
	class GameObject;
	class Material;
	class Light;
	class FrontToBackDoubleLinkedList :public DoubleLinkedList {
	public:
		float mDistanceToCamera;
	};
	class DrawCall:public FrontToBackDoubleLinkedList {
	public:
		Material *mMaterial;
		Camera*mCamera;
		VBO *mVBO;
		EBO *mEBO;
        GameObject*mGameObject;
		CustomComponent*mCustomComponent;
	public:
		DrawCall();
		~DrawCall();
		void Clear();
		void Rendering();
		void RenderingOpaque();
		void RenderingTransparent();
		void SetUpDepthMap(RenderPass*pass);
		void SetUpCamera(RenderPass*pass);
		void SetUpOnePassLights(RenderPass*pass);
		void SetUpLight(RenderPass*pass,Light*light);
		void RenderNoLit(RenderPass*pass);
		void RenderOnePass(RenderPass*pass);
		void RenderForwardBasePass(RenderPass*pass);
		void RenderForwardAdditivePass(RenderPass*pass);
		void ForwardRendering();
		void RenderingDepth();
	};
	class RenderQueue {
	public:
		Camera*mCamera;
		RenderQueue(Camera*camera){
			mCamera = camera;
			mOpaqueDrawCall = nullptr;
			mTransparentDrawCall = nullptr;
			mLastTransparentDrawCall = nullptr;
			mUIDrawCall = nullptr;
			mDepthDrawCall = nullptr;
			mLastUIDrawCall = nullptr;
		}
		DrawCall *mOpaqueDrawCall, *mTransparentDrawCall,*mLastTransparentDrawCall, *mUIDrawCall,*mLastUIDrawCall, *mDepthDrawCall;
		void AppendOpaqueDrawCall(DrawCall*dc);
		void AppendTransparentDrawCall(DrawCall*dc);
		void AppendUIDrawCall(DrawCall*dc);
		void AppendDepthDrawCall(DrawCall*dc);
		void RenderOpaque();
		void RenderTransparent();
		void RenderUI();
		void RenderDepth();
	};
}
