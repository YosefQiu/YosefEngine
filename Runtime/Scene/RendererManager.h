#pragma once
#include "Runtime/Render/VertexData.h"
#include "Runtime/Utils/LinkedList.h"
#include <map>
#include "Runtime/Render/RenderMisc.h"

namespace YOSEF{
	class RendererManager{
	public:
		RendererManager();
		RenderArchitecture mRenderArchitecture;
	public:
		void InitDefaultColorMaterial();
		void InitDefaultSimpleColorMaterial();
		void InitDefault2DMaterial();
		void InitDynamicFontMaterial();
		void InitVideoSpriteMaterial();
		void InitDefaultFrameBufferRenderMaterial();
		void InitStencilRenderMaterial();
	};
	RendererManager&GetRendererManager();
}
