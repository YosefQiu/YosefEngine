#include "SceneManager.h"
#include "Runtime/Render/YOSEFGL.h"
#include "Runtime/Debugger/Log.h"
#include "External/LibCurl/include/curl/curl.h"
extern "C" void InitMemory();
static YOSEF::SceneManager *sSceneManager;
namespace YOSEF 
{
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
	void SceneManager::Pause(){
		mbIsPlaying = false;
	}
	void SceneManager::Reset(){
	}
	void SceneManager::Stop() {
		mbIsPlaying = false;
	}
	void SceneManager::Render() {
		glClearColor(0.1f, 0.4f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void SceneManager::GetCanvasSize(int&width, int&height) {
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
	GetSceneManager()->Init();
}
extern "C" void OnQuitEngine() {
}
extern "C" void Render() {
	GetSceneManager()->Render();
}
extern "C" void OnViewSizeChange(int x, int y, int width, int height) {
	GetSceneManager()->OnViewSizeChange(x, y, width, height);
}
YOSEF::SceneManager * GetSceneManager() {
	if (sSceneManager == nullptr) {
		sSceneManager = new YOSEF::SceneManager();
	}
	return sSceneManager;
}
