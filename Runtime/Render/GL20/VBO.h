#pragma once
#include "BufferObject.h"
namespace YOSEF{
	class VBO:public BufferObject{
	public:
		VBO(YOSEFUInt16 nSize=0,GLenum hint=GL_DYNAMIC_DRAW);
		virtual ~VBO();
		YOSEFUInt16 mSize;
		YOSEFUInt16 mDrawStartIndex;
		YOSEFUInt16 mDrawCount;
		void Init(int count, GLenum hint = GL_DYNAMIC_DRAW);
		void Draw(GLenum primitiveType);
	};
}