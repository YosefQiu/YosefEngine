#include "TextureResource.h"
#include "ResourceManager.h"
#include "Runtime/String/StringUtils.h"

namespace YOSEF
{
	TextureResource* TextureResource::CreateTextureResourceFromRawData(const char*path, Data&data){
		Serializer::TextureInfo*textureInfo = new (kMemTextureId)Serializer::TextureInfo;
		textureInfo->set_imagedata(data.mData, data.mDataLen);
		TextureResource*textureResource = new (kMemTextureId)TextureResource;
		if (StringUtils::EndWithI(path, ".png")){
			textureResource->mType = ResourceTypePNGImage;
		}else if (StringUtils::EndWithI(path, ".jpg")) {
			textureResource->mType = ResourceTypeJPGImage;
		}else if (StringUtils::EndWithI(path, ".bmp")) {
			textureResource->mType = ResourceTypeBMPImage;
		}
		textureResource->mName = path;
		textureResource->mResourceData = textureInfo;
		textureResource->mTextureResourceType = kTextureResourceTypeTextureInfo;
		return textureResource;
	}
	TextureResource* TextureResource::LoadTexture(Serializer::RuntimeAsset*asset){
		Serializer::Texture*texture = new (kMemTextureId)Serializer::Texture;
		if (texture->ParseFromArray(asset->rawdata().c_str(), asset->rawdata().length())){
			if (texture->has_image_data()) {
				TextureResource*textureResource = new (kMemTextureId)TextureResource;
				textureResource->mType = (ResourceType)asset->type();
				textureResource->mResourceData = texture;
				textureResource->mTextureResourceType = kTextureResourceTypeTexture;
				return textureResource;
			}
		}
		delete texture;
		Serializer::TextureInfo*textureInfo = new (kMemTextureId)Serializer::TextureInfo;
		if (textureInfo->ParseFromArray(asset->rawdata().c_str(), asset->rawdata().length())){
			TextureResource*textureResource = new (kMemTextureId)TextureResource;
			textureResource->mType = (ResourceType)asset->type();
			textureResource->mResourceData = textureInfo;
			textureResource->mTextureResourceType = kTextureResourceTypeTextureInfo;
			return textureResource;
		}
		delete textureInfo;
		return nullptr;
	}
}
