#pragma once
#include "Runtime/Render/GL20/TextureCube.h"
#include "Runtime/Render/GL20/VBO.h"
#include "Runtime/Render/YosefGL.h"
#include "Runtime/Render/VertexData.h"

namespace YOSEF{
	class Material;
	class SkyBox{
	public:
		SkyBox();
		void Render();
		YOSEFAny mCamera;
		VBO mVBO;
		VertexData *mVertexData;
		SmartPtr<Material> mMaterial;
		SmartPtr<TextureCube> mCubeMap;
	};
}