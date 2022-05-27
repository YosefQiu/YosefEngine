#include "IndexBuffer.h"
namespace YOSEF{
	IndexBuffer::IndexBuffer(YOSEFUInt16 size):mIndexes(nullptr){
		mSize = size;
		mBufferSize = 0;
		if (mSize != 0) {
			mIndexes = new YOSEFUInt16[mSize];
			mBufferSize = sizeof(YOSEFUInt16)*mSize;
			memset(mIndexes, 0, mBufferSize);
		}
	}
    IndexBuffer::~IndexBuffer(){
        if (mIndexes!=nullptr){
            delete mIndexes;
			mIndexes = nullptr;
        }
		mSize = 0;
		mBufferSize = 0;
    }
	void IndexBuffer::Init(YOSEFUInt16 size) {
		mSize = size;
		mIndexes = new YOSEFUInt16[mSize];
		mBufferSize = sizeof(YOSEFUInt16)*mSize;
		memset(mIndexes, 0, mBufferSize);
	}
}
