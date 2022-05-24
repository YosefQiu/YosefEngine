#include "EBO.h"
#include "Runtime/Debugger/Debugger.h"
namespace YOSEF{
	EBO::EBO(int nCount, GLenum hint):BufferObject(GL_ELEMENT_ARRAY_BUFFER,nCount*sizeof(YOSEFUInt16),hint){
		mIndexCount = nCount;
		mIndexCountForDraw = mIndexCount;
		mStartIndex = 0;
	}
	EBO::~EBO(){

	}
	void EBO::Init(int indexcount, GLenum hint) {
		mIndexCount = indexcount;
		mIndexCountForDraw = indexcount;
		BufferObject::Init(GL_ELEMENT_ARRAY_BUFFER, mIndexCount * sizeof(YOSEFUInt16), hint);
	}
	void EBO::Draw(GLenum primitiveType) {
		if(Active()){
            glDrawElements(primitiveType, mIndexCountForDraw, GL_UNSIGNED_SHORT, (void*)(sizeof(YOSEFUInt16)*mStartIndex));
            Restore();
        }
	}
}
