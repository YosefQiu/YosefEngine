#pragma once
namespace YOSEF {
	class SceneManager {
	public:
		SceneManager();
		void Init();
		void Render();
		void GetCanvasSize(int&width, int&height);
		void OnViewSizeChange(int x, int y, int width, int height);
		void Pause();
		void Play();
		void Step();
		void Reset();
		void Stop();
		int mFullResolutionWidth, mFullResolutionHeight;
		int mMaxFPS;
		float mFixedTimePerFrame;
		float mUIMaxScale;
		bool mbIsPlaying;
	};
}
YOSEF::SceneManager * GetSceneManager();