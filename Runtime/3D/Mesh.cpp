#include "Mesh.h"
#include "Runtime/Scene/GameObject.h"
#include "Runtime/Serializer/Mesh.serializer.h"
#include "Runtime/Geometry/Intersection.h"
namespace YOSEF{
	Mesh::Mesh() :mVertexData(nullptr), mMaterial(nullptr), mRes(nullptr){
		mDataChanged = false;
		mPrimitiveType = GL_TRIANGLES; 
		mVertexData = new (kMemDefaultId)VertexData;
		mStart = 0;
		mCount = 0;
		mIndexChanged = false;
		mbIsBoundingVolumeDirty = true;
		mbOffsetMatrixChanged = true;
	}
	Mesh::~Mesh(){
        mEBO.mIdentifier=0;
		delete mVertexData;
	}
	void Mesh::InitBoundingBox() {
	}
	const Sphere&Mesh::GetBoundingVolume() {
		if (mbIsBoundingVolumeDirty){
			mbIsBoundingVolumeDirty = false;
			mBoundingVolume.Set(mMinMaxAABB);
			const Matrix4x4&world_matrix = mOwner->GetWorldMatrix();
			Matrix4x4 mesh_world_matrix;
			Matrix4x4MultiplyMatrix4x4(world_matrix.mData, mOffsetMatrix.mData, mesh_world_matrix.mData);
			mBoundingVolume.mCenter = mesh_world_matrix * Vector4f(mBoundingVolume.mCenter+mBoundingBoxOffset);
			float scaleX = YOSEF_SQRTF(YOSEF_SQUARE(mesh_world_matrix.mData[0]) + YOSEF_SQUARE(mesh_world_matrix.mData[1]) + YOSEF_SQUARE(mesh_world_matrix.mData[2]));
			float scaleY = YOSEF_SQRTF(YOSEF_SQUARE(mesh_world_matrix.mData[4]) + YOSEF_SQUARE(mesh_world_matrix.mData[5]) + YOSEF_SQUARE(mesh_world_matrix.mData[6]));
			float scaleZ = YOSEF_SQRTF(YOSEF_SQUARE(mesh_world_matrix.mData[8]) + YOSEF_SQUARE(mesh_world_matrix.mData[9]) + YOSEF_SQUARE(mesh_world_matrix.mData[10]));
			float scale = YOSEF::Max(scaleX, scaleY);
			scale = YOSEF::Max(scale,scaleZ);
			mBoundingVolume.mRadius *= scale;
		}
		return mBoundingVolume;
	}
	void Mesh::SetVertexData(const void*data, int datasize){
		memcpy(mVertexData->mData, data, datasize);
		mDataChanged = true;
		mbIsBoundingVolumeDirty = true;
	}
	void Mesh::UpdateVertexPosition(int nIndex, float x, float y, float z, float w /* = 1.0f */){
		mDataChanged = true;
		mVertexData->GetBuffer<VertexDataFull>()[nIndex].mVertex.Set(x, y, z, w);
		mMinMaxAABB.Encapsulate(mVertexData->GetBuffer<VertexDataFull>()[nIndex].mVertex);
	}
	void Mesh::UpdateVertexTexcoord(int nIndex, float x, float y, float z, float w /* = 1.0f */){
		mDataChanged = true;
		mVertexData->GetBuffer<VertexDataFull>()[nIndex].mTexCoord0.Set(x, y, z, w);
	}
	void Mesh::UpdateVertexNormal(int nIndex, float x, float y, float z, float w /* = 1.0f */){
		mDataChanged = true;
		mVertexData->GetBuffer<VertexDataFull>()[nIndex].mNormal.Set(x, y, z, w);
	}
	void Mesh::UpdateVertexTangent(int nIndex, float x, float y, float z, float w /* = 1.0f */){
		mDataChanged = true;
		mVertexData->GetBuffer<VertexDataFull>()[nIndex].mTangent.Set(x, y, z, w);
	}
	void Mesh::UpdateVertexTexcoord1(int nIndex, float x, float y, float z, float w /* = 1.0f */){
		mDataChanged = true;
		mVertexData->GetBuffer<VertexDataFull>()[nIndex].mTexCoord1.Set(x,y,z,w);
	}
	void Mesh::UpdateIndex(YOSEFUInt16 nIndex, YOSEFUInt16 indice){
		if (nIndex<mIndexBuffer.mSize){
			mIndexBuffer.mIndexes[nIndex] = indice;
			mIndexChanged = true;
		}else{
			Error("mesh:update index, out of range %d max(%d)",nIndex,mIndexBuffer.mSize);
		}
	}
	void Mesh::SetPrimiviteType(GLenum type){
		mPrimitiveType = type;
		mMaterial->SetPrimitive(GL_TRIANGLE_STRIP);
	}
	void Mesh::SetRenderRange(int nStart, int nCount){
		mStart = nStart;
		mCount = nCount;
	}
	void Mesh::SetVertexCount(int vertexCount){
		mVertexData->SetBufferSize(vertexCount);
		mVBO.Init(vertexCount);
	}
	void Mesh::SetIndexCount(int nIndexCount){
		mIndexBuffer.Init(nIndexCount);
		mEBO.Init(nIndexCount);
	}
	void Mesh::SetMaterial(Material*mat){
		mMaterial = mat;
	}
	void Mesh::AnimateModelMatrix(const void*value) {
		memcpy(mOffsetMatrix.mData, value, sizeof(float) * 16);
		mbOffsetMatrixChanged = true;
	}
	void Mesh::SetName(const char*name){
		mName = name;
	}
	void Mesh::Update(float deltaTime){
		if (mDataChanged){
			VertexDataFull*vertexes = mVertexData->GetBuffer<VertexDataFull>();
			mVBO.SubData(vertexes, mVertexData->mBufferSize);
			mDataChanged = false;
		}
		if (mbPositionChanged || mbOffsetMatrixChanged){
			if (mMaterial != nullptr) {
				mbIsBoundingVolumeDirty = true;
				const Matrix4x4&world_matrix=mOwner->GetWorldMatrix();
				Matrix4x4 mesh_world_matrix = world_matrix;
				mesh_world_matrix *= mOffsetMatrix;
				Matrix3x3 rotate_matrix(mesh_world_matrix);
				rotate_matrix.InvertTranspose();
				Matrix4x4 normal_matrix(rotate_matrix);
				mMaterial->SetMatrix4Property(UniformDefines::Matrix_M_NameInShader, mesh_world_matrix.mData);
				mMaterial->SetMatrix4Property(UniformDefines::Matrix_IT_M_NameInShader, normal_matrix.mData);
				mbPositionChanged = false;
				mbOffsetMatrixChanged = false;
			}
		}
		if (mIndexChanged){
			mIndexChanged = false;
			mEBO.SubData(mIndexBuffer.mIndexes, mIndexBuffer.mBufferSize);
		}
	}
	void Mesh::Render(RenderQueue*rq
#if YOSEF_EDITOR
		, DrawCallInfo &rs
#endif
	){
		if (mMaterial==nullptr){
			return;
		}
		if (mVBO.mSize == 0) {
			return;
		}
		float distance_from_camera = GetDistanceFromCamera(rq);
		if (distance_from_camera < 0.0f) {
			return;
		}
	}
	void Mesh::RenderShadowMap(RenderQueue*rq
#if YOSEF_EDITOR
		, DrawCallInfo &rs
#endif
	) {
		if (mMaterial == nullptr) {
			return;
		}
		if (mVBO.mSize == 0) {
			return;
		}
		if (mMaterial->mbCastShadow == false) {
			return;
		}
		float distance_from_camera = GetDistanceFromCamera(rq);
		if (distance_from_camera < 0.0f) {
			return;
		}
	}
	float Mesh::GetDistanceFromCamera(RenderQueue*rq) {
		GetBoundingVolume();
		return 0.0f;
	}
}
