#include "TextureUnit.h"
#include "Runtime/Debugger/Debugger.h"
namespace YOSEF{
	TextureUnit::TextureUnit() : Object(1) {
		mTextureID = 0;
		mTextureType = GL_NONE;
	}
	TextureUnit::~TextureUnit(){
		if (mTextureID != 0
#if YOSEF_ANDROID
            && mTextureType!=GL_TEXTURE_EXTERNAL_OES
#endif
            ) {
			OGL_CALL(glDeleteTextures(1, &mTextureID));
		}
	}
}
