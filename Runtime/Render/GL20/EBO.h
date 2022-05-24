#pragma once
#include "BufferObject.h"

namespace YOSEF{
	class EBO :public BufferObject{
	public:
		EBO(int nCount=0, GLenum hint = GL_DYNAMIC_DRAW);
		virtual ~EBO();
		YOSEFUInt16 mIndexCount;
		YOSEFUInt16 mIndexCountForDraw;
		YOSEFUInt16 mStartIndex;
		void Init(int indexcount, GLenum hint=GL_DYNAMIC_DRAW);
		void Draw(GLenum primitiveType);
	};
}
