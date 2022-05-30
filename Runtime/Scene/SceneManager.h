#pragma once
#include <vector>
namespace YOSEF {
	class Camera;
	class GameObject;
	class SceneManager {
	public:
		SceneManager();
		void Init();
		void Render();
		void GetCanvasSize(int& width, int& height);
		void OnViewSizeChange(int x, int y, int width, int height);
		void Pause();
		void Play();
		void Step();
		void Reset();
		void Stop();
		void AddOffScreenCamera(Camera* camera);
		void RemoveOffScreenCamera(Camera* camera);
		void AddCamera(Camera* camera);
		void RemoveCamera(Camera* camera);
		void InitTestImageSprite();
		void InitTestCamera();
		void InitTestLabel();
		void InitTestImageSprite9();
		void InitTest2DAnimation();
		void InitTest3DAnimation();
		int mFullResolutionWidth, mFullResolutionHeight;
		int mMaxFPS;
		float mFixedTimePerFrame;
		float mUIMaxScale;
		bool mbIsPlaying;
		GameObject* mRootObject;
		std::vector<Camera*> mOffScreenCameras;
		std::vector<Camera*> mCameras;
	};
}
YOSEF::SceneManager* GetSceneManager();