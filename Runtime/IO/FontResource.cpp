#include "FontResource.h"
#include "ResourceManager.h"
namespace YOSEF{
	FontResource*FontResource::LoadFontResource(Serializer::RuntimeAsset*asset){
		FontResource*fontResource = new (kMemDefaultId)FontResource;
		fontResource->mName = asset->guid();
		return fontResource;
	}
}