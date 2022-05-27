#pragma once
#include "Runtime/Base/Object.h"
#include "Runtime/Render/YosefGL.h"
#include "Runtime/Render/GL20/Texture2D.h"
#include "Runtime/Render/Material.h"
#include "TextureRectangleNode.h"
#include "Runtime/Utils/SmartPtr.h"

namespace YOSEF{
	class DynamicTextureAtlas :public Object {
	public:
		DynamicTextureAtlas(YOSEFUInt16 width = 4096, YOSEFUInt16 height = 4096);
		std::map<YOSEFUInt64, TextureRectangleNode*> mTextureTiles;
		TextureRectangleNode*mRootNode;
		Texture2D* mTexture;
		SmartPtr<Material> mMaterial;
		TextureRectangleNode* AddTextureTile(YOSEFUInt64 ID, int width, int height, YOSEFUInt8 *imageData);
		static DynamicTextureAtlas* GetDefaultDynamicTextureAtlas();
		static std::vector<DynamicTextureAtlas*> mCachedAtlas;
	};
}