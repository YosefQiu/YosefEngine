#pragma once
#include "Runtime/Render/YosefGL.h"
#include "Runtime/Render/VertexData.h"
#include "Runtime/Render/Material.h"
#include "Runtime/Render/GL20/VBO.h"
namespace YOSEF{
	class FullScreenQuad{
	public:
		FullScreenQuad();
		~FullScreenQuad();
		void Init();
		void Render(Material*material);
		VBO mVBO;
	};
}
