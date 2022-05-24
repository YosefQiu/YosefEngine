#pragma once
#include "Runtime/RuntimePrefix.h"
#include "Runtime/Render/YosefGL.h"
namespace YOSEF{
	class RBO{
	public:
		GLuint mRenderBufferObject;
		RBO();
		~RBO();
		void Init(int width,int height);
		void Resize(int width, int height);
	};
}