#include "SceneManager.h"
#include "Runtime/Render/YosefGL.h"
#include "Runtime/Debugger/Log.h"
#include "Runtime/Debugger/Debugger.h"
#include "External/LibCurl/include/curl/curl.h"
#include "Runtime/Font/DynamicFont.h"
#include "GameObject.h"
#include "Runtime/2D/ImageSprite.h"
#include "Runtime/2D/ImageSprite9.h"
#include "Runtime/2D/Label.h"
#include "Runtime/Animation/SpineAvatar.h"
#include "Runtime/Render/Camera.h"
#include "Runtime/Render/DrawCall.h"
extern "C" void InitMemory();
static YOSEF::SceneManager* sSceneManager;
namespace YOSEF {
	//for editor end
	SceneManager::SceneManager() :mFullResolutionWidth(0), mFullResolutionHeight(0),
		mMaxFPS(0), mFixedTimePerFrame(0.0f) {
		sSceneManager = this;
		mbIsPlaying = false;
		mUIMaxScale = 1.0f;
	}
	void SceneManager::Play() {
		mbIsPlaying = true;
	}
	void SceneManager::Step() {
	}
	void SceneManager::Pause() {
		mbIsPlaying = false;
	}
	void SceneManager::Reset() {
	}
	void SceneManager::Stop() {
		mbIsPlaying = false;
	}
	void SceneManager::AddCamera(Camera* camera) {
		mCameras.push_back(camera);
	}
	void SceneManager::RemoveCamera(Camera* camera) {
		auto iter = mCameras.begin();
		auto iterEnd = mCameras.end();
		for (; iter != iterEnd; ++iter) {
			if (*iter == camera) {
				mCameras.erase(iter);
				break;
			}
		}
	}
	void SceneManager::AddOffScreenCamera(Camera* camera) {
		mOffScreenCameras.push_back(camera);
	}
	void SceneManager::RemoveOffScreenCamera(Camera* camera) {
		auto iter = mOffScreenCameras.begin();
		auto iterEnd = mOffScreenCameras.end();
		for (; iter != iterEnd; ++iter) {
			if (*iter == camera) {
				mOffScreenCameras.erase(iter);
				break;
			}
		}
	}
	void SceneManager::InitTestImageSprite() {
		GameObject* go = new GameObject;
		mRootObject->AddChild(go);
		go->SetLocalPosition(0.0f, 0.0f, -1.0f);
		ImageSprite* is = new ImageSprite;
		is->SetOwner(go);
	}
	void SceneManager::InitTestCamera() {
		GameObject* go = new GameObject;
		mRootObject->AddChild(go);
		Camera* camera = new Camera;
		camera->SetOwner(go);
		GetSceneManager()->AddCamera(camera);
		camera->mCameraMode = Camera::CameraMode::OrthoMode;
		int width, height;
		GetSceneManager()->GetCanvasSize(width, height);
		camera->OnViewPortSizeChange(width, height);
	}
	void SceneManager::InitTestLabel() {
		GameObject* go = new GameObject;
		mRootObject->AddChild(go);
		go->SetLocalPosition(0.0f, 0.0f, -1.0f);
		Label* label = new Label;
		label->Initialize();
		label->SetOwner(go);
		label->SetText("HelloWorld!");
	}
	void SceneManager::InitTestImageSprite9() {
		GameObject* go = new GameObject;
		mRootObject->AddChild(go);
		go->SetLocalPosition(0.0f, 0.0f, -1.0f);
		ImageSprite9* is = new ImageSprite9;
		is->SetOwner(go);
		Texture2D* texture = Texture2D::LoadTexture2D("Resource/powerup.atlas");
		is->SetTexture("U_MainTexture", texture);
	}
	void SceneManager::InitTest2DAnimation() {
		GameObject* uiroot = new GameObject;
		mRootObject->AddChild(uiroot);
		uiroot->SetLocalPosition(0.0f, 0.0f, -1.0f);
		GameObject* go = new GameObject;
		uiroot->AddChild(go);
		Material* material = new Material;
		*material = *Material::mCachedMaterials["builtin/Material/Texture2D"];
		material->mbSharedMaterial = false;
		material->EnableCull(false);
		SpineAvatar* avatar = new SpineAvatar;
		avatar->SetOwner(go);
		Texture2D* texture = Texture2D::LoadTexture2D("Resource/powerup.atlas");
		material->SetTextureProperty("U_MainTexture", texture);
		avatar->mSharedMaterial = material;
		Resource* avatar_resource = Resource::LoadAssetWithUserPath("Resource/powerup.avatar");
		if (avatar_resource != nullptr) {
			Serializer::SpineAvatar* avatar_data = new (kMemAnimationId)Serializer::SpineAvatar;
			if (avatar_data->ParseFromArray(avatar_resource->mAssetBundle->rawdata().c_str(), avatar_resource->mAssetBundle->rawdata().size())) {
				avatar->mSpineAvatarData = avatar_data;
				go->InitSelfWithSerializedData(avatar_data->mutable_setup_pose(), avatar->mSharedMaterial.mPtr);
				avatar->ResetToTPose();
				for (int animation_index = 0; animation_index < avatar_data->animations_size(); ++animation_index) {
					avatar->AttachAnimation(avatar_data->animations(animation_index));
				}
				avatar->Play("bounce");
				avatar->mAnimationMode = kAnimationModeLoop;
			}
		}
		go->SetLocalPosition(0.0f, -200.0f, 0.0f);
	}
	void SceneManager::Render() {
		glViewport(0, 0, 1280, 720);
		OGL_CALL(glClearColor(0.1f, 0.4f, 0.6f, 1.0f));
		OGL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT));
		//update script、this may change transform/component
		mRootObject->UpdateScriptsRecursively(0.016f);
		//update transform
		mRootObject->UpdateTransformRecursively();
		//update component
		mRootObject->UpdateComponentRecusively(0.016f);
		//sync rendering geometry to physic world
		mRootObject->SyncPhysicsComponentRecusively(0.016f);
		if (mCameras.empty()) {
			return;
		}
		//render offscreen camera
		//render scene
		//render ui
		Camera* camera = mCameras[0];
		camera->ClearBackground();
		RenderQueue render_queue(camera);
		mRootObject->RenderComponentRecursively(camera, &render_queue);
		render_queue.RenderUI();
	}
	void SceneManager::GetCanvasSize(int& width, int& height) {
		width = mFullResolutionWidth;
		height = mFullResolutionHeight;
	}
	void SceneManager::OnViewSizeChange(int x, int y, int width, int height) {
		if (mFullResolutionWidth == width && mFullResolutionHeight == height) {
			return;
		}
		mFullResolutionWidth = width;
		mFullResolutionHeight = height;
	}
	void SceneManager::Init() {
		mRootObject = new GameObject;
		mRootObject->mLayer = 0xFFFFFFFF;
		mRootObject->mName = "InternalRoot";
	}
}
//1、init log
//2、init first system info
//3、init memory pool
//4、init lua engine & export YOSEF core runtime lua api
//5、init physics engine
//6、init image error reporter
//7、init default engine asset bundle map
//8、init physics engine
extern "C" void InitEngineCore() {
	curl_global_init(CURL_GLOBAL_ALL);
	InitMemory();
	YOSEF::Resource::Init();
	YOSEF::ResourceManager::Init();
	InitEngineLog("Log/EngineCoreLog");
	Info("curl version %s", curl_version());
}
//9、init font engine
//10、init builtin resources
//11、init default scene root object
//12、init builtin scripts
//13、init graphic engine for post rendering
//should be inited after opengl setup
extern "C" void InitRuntime() {
	YOSEF::GlobalRenderState::Init();
	YOSEF::DynamicFont::InitFTLib();
	GetSceneManager()->Init();
	//V_Color
	YOSEF::GetRendererManager().InitDefaultColorMaterial();
	//U_Color
	YOSEF::GetRendererManager().InitDefaultSimpleColorMaterial();
	//sprite 2d material
	YOSEF::GetRendererManager().InitDefault2DMaterial();
	//dynamic font
	YOSEF::GetRendererManager().InitDynamicFontMaterial();
	YOSEF::GetRendererManager().InitDefaultFrameBufferRenderMaterial();
	YOSEF::GetRendererManager().InitStencilRenderMaterial();
}
extern "C" void OnQuitEngine() {
}
extern "C" void Render() {
	GetSceneManager()->Render();
}
extern "C" void OnViewSizeChange(int x, int y, int width, int height) {
	GetSceneManager()->OnViewSizeChange(x, y, width, height);
}
YOSEF::SceneManager* GetSceneManager() {
	if (sSceneManager == nullptr) {
		sSceneManager = new YOSEF::SceneManager();
	}
	return sSceneManager;
}
