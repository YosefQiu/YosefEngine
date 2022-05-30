#pragma once
#include "YosefResource.h"

namespace YOSEF{
	class FontResource:public Resource{
	public:
		static FontResource * LoadFontResource(Serializer::RuntimeAsset*name);
		static FontResource* CreateFontResourceWithRawData(const char* path, Data& data);
	};
}