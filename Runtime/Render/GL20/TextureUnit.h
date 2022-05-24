#pragma once
#include "Runtime/RuntimePrefix.h"
#include "Runtime/Base/Object.h"
#include "Runtime/Render/YosefGL.h"
#include "Runtime/Utils/SmartPtr.h"
namespace YOSEF{
	class TextureUnit : public Object{
	public:
		GLuint mTextureID;
		GLenum mTextureType;
		TextureUnit();
		virtual ~TextureUnit();
	};
}
