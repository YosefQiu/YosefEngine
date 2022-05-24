#pragma once
#include "YosefResource.h"

namespace YOSEF
{
	class ShaderResource :public Resource
	{
	public:
		ShaderResource();
		static ShaderResource*LoadShader(Serializer::RuntimeAsset*asset);
	};
}