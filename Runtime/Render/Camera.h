#pragma once
#include "Runtime/RuntimePrefix.h"
#include "Runtime/Allocator/DefaultAllocator.h"
#include "Runtime/Math/YosefMatrix4x4.h"
#include "Runtime/Base/Component.h"
#include "Runtime/Math/Color.h"
#include "Runtime/Geometry/Plane.h"
#include "Runtime/Math/Rect.h"
#include "Runtime/Geometry/Ray.h"
#include "GL20/FBO.h"
#include "YosefGL.h"
namespace YOSEF{
	enum FrustumPlane{
		kFrustumPlaneLeft,
		kFrustumPlaneRight,
		kFrustumPlaneBottom,
		kFrustumPlaneTop,
		kFrustumPlaneNear,
		kFrustumPlaneFar,
		kFrustumPlaneCount,
	};
	struct CullingParameters{
		Plane     cullingPlanes[kFrustumPlaneCount];
	};
	class Camera:public Component{
	public:
		enum ClearMode {
			kClearModeSkybox = 1,
			kClearModeSolidColor = 2,
			kClearModeDepthOnly = 3,
			kClearModeDontClear = 4,
			kClearModeClearAll=5
		};
		enum CameraMode{
			PerspectiveMode = 1,
			OrthoMode = 2
		};
	public:
		Camera();
		virtual ~Camera();
		void ClearBackground();
		void LookAt(Vector3f eye,Vector3f lookAt,Vector3f up);
		void SetProjection(float fovy,float aspect,float zNear,float zFar);
		void OnViewPortSizeChange(int width,int height);
		void SetClearColor(YOSEFUInt8 r,YOSEFUInt8 g,YOSEFUInt8 b,YOSEFUInt8 a);
		bool GetViewRect(Rect<float>&rect);
		void ScreenCoordToOpenGLCoord(float & x,float & y);
		int GetScreenShot(unsigned char **pixel,int&width,int&height);
		CullingParameters mCullingParameters;
		virtual void Update(float deltaTime);
	public:
		DECLEAR_YOSEF_CLASS(Camera)
	public:
		Matrix4x4			mProjectionMatrix;
		Matrix4x4			mViewMatrix;
		float               mDepth;
		float				mOrthoModeSize;
		ClearMode			mClearFlags;
		float				mResolutionWidth;
		float				mResolutionHeight;
		int					mViewWidth;
		int					mViewHeight;
		CameraMode			mCameraMode;//perspective or ortho
		YOSEFUInt32			mCullingFlags;
		Color4B				mClearColor;
		float               mFieldOfView;
		float               mAspect;
		float               mNearClip;
		float               mFarClip;
		FBO					*mFBO;
		bool				mbOffScreen;
		FBO					*mDepthFBO;
		bool				mbRenderDepth;
		static bool SortCameras(const Camera *l,const Camera *r){
			if (l->mDepth<r->mDepth){
				return true;
			}else{
				return false;
			}
		}
	};
	void ExtractProjectionPlanes(const Matrix4x4& finalMatrix, Plane* outPlanes);
}