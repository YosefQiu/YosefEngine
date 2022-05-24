#pragma once
#include "Runtime/RuntimePrefix.h"
#include "Runtime/Render/YosefGL.h"
#include "Runtime/Render/RenderMisc.h"
#include "Runtime/IO/TextureResource.h"
#include "Runtime/Serializer/TextureInfo.serializer.h"
#include "Runtime/Utils/SmartPtr.h"
#include <map>
#include <string>
#include "TextureUnit.h"

namespace YOSEF{
	class Texture2D : public TextureUnit{
	public:
		Texture2D();
		~Texture2D();
		void InitTexture2D(YOSEFUInt16 width = 1024, YOSEFUInt16 height = 1024,
			GLenum internalformat = GL_RGBA,
			GLenum srcFormat = GL_RGBA,
			GLenum minFilter = GL_LINEAR,
			GLenum magFilter = GL_LINEAR,
			GLenum filterS = GL_CLAMP_TO_EDGE,
			GLenum filterT = GL_CLAMP_TO_EDGE
		);
		void InitDepthTexture(YOSEFUInt16 width=1024,YOSEFUInt16 height=1024);
		GLenum mMinFilter;
		GLenum mMagFilter;
		GLenum mFilterT;
		GLenum mFilterS;
		GLenum mInternalFormat;
		GLenum mSrcFormat;
		GLuint mWidth,mHeight;
		SmartPtr<Resource> mRes;
		std::unordered_map<std::string, Serializer::Sprite*> mSprites;
		void UploadTexture(YOSEFAny imageData);
		void TexParameteri(GLenum name, GLenum value);
		void UploadETC1RGBTexture(YOSEFUInt8*imageData, YOSEFUInt16 paddedWidth, YOSEFUInt16 paddedHeight, YOSEFUInt8*alphaChannel=nullptr);
		void UploadSubTexture(YOSEFUInt16 x,YOSEFUInt16 y,YOSEFUInt16 width,YOSEFUInt16 height,GLenum format,GLenum dataType,YOSEFUInt8*pData);
		Serializer::Sprite*GetSprite(const char *name);
		void InitSpriteInfo(Serializer::Texture*texture);
	public:
		//input texture name
		static std::unordered_map<std::string, Texture2D*> mTextures;
		static Texture2D*LoadTexture2D(const char*name);
		static Texture2D*CreateTextureFromMemory(const char *data, int dataLen,GLenum minFilter = GL_LINEAR,
			GLenum magFilter = GL_LINEAR,
			GLenum filterS = GL_CLAMP_TO_EDGE,
			GLenum filterT = GL_CLAMP_TO_EDGE);
		static Texture2D*CreateTextureWidthFreeImage(TextureResource*jpg);
		static Texture2D*CreateTextureFromETC1RGBFile(TextureResource*etc1rgb);
		static Texture2D*CreateTextureFromPVRTC4RGBAFile(TextureResource*pvrtcgrba);
		static Texture2D*CreateTextureFromRawLuminance8(TextureResource*pvrtcgrba);
		static Texture2D*GetCachedTexture2D(const char*path);
		static Serializer::ImageTile*GetSpriteInfo(const char*atlasName,const char*spriteName);
		static int mTextureMemoryCount;
		static void UnloadTexture(const char*name);
		static Texture2D* mTextureError;
	public:
		DECLEAR_YOSEF_CLASS(Texture2D)
	};
}
