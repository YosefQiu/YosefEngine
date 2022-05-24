#include "VertexData.h"
namespace YOSEF{
	static const YOSEFSInt8 TypeVertexData3D = sizeof(VertexDataFull);
	VertexData::VertexData() :mData(nullptr){
		mCount = 0;
		mBufferSize = 0;
		mType = TypeVertexData3D;
	}
    VertexData::~VertexData(){
        if (mData !=nullptr){
            delete [] mData;
        }
    }
	void VertexData::SetBufferSize(int count) {
		mCount = count;
		mBufferSize = mCount*mType;
		mData = new VertexDataFull[count];
	}
}
