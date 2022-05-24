#pragma once
#include "YosefResource.h"
#include "YosefResourceType.h"
#include "Runtime/Serializer/TextureAtlas.serializer.h"
namespace YOSEF{
	class ImageResource :public Resource {
	public:
		ImageResource();
		~ImageResource();
		Data mPixelData;
		int mWidth, mHeight;
		int mBPP;
		static ImageResource* Init(const char *filepath);
		bool InitWithRawImageFileData(unsigned char * const data, int dataLen);//create from png/bmp...
		bool InitWithTextureAssetData(const unsigned char*data, int dataLen);//create from YOSEF asset
		void Save(const char*filePath);
		DECLEAR_YOSEF_CLASS(ImageResource)
	}; 
}