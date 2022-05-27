#pragma once
#include "Runtime/Base/Component.h"
#include "Runtime/Render/VertexData.h"
#include "Runtime/Render/IndexBuffer.h"
#include "Runtime/Render/YosefGL.h"
#include "Runtime/Render/GL20/VBO.h"
#include "Runtime/Render/GL20/EBO.h"
#include "Runtime/Render/Material.h"
#include "Runtime/Serializer/Mesh.serializer.h"
#include "Runtime/Geometry/Geometry.h"
namespace YOSEF{
	class Mesh :public Component{
	public:
		VertexData *mVertexData;
		IndexBuffer mIndexBuffer;
		VBO mVBO;
		EBO	mEBO;
		SmartPtr<Material> mMaterial;
		SmartPtr<Resource> mRes;
		bool mDataChanged;
		bool mIndexChanged;
		bool mbOffsetMatrixChanged;
		bool mbIsBoundingVolumeDirty;
		GLenum mPrimitiveType;
		int mStart, mCount;
		Matrix4x4 mOffsetMatrix;
	public:
		BoundingVolumeType mBoundingVolumeType;
		MinMaxAABB mMinMaxAABB;
		Sphere mBoundingVolume;
		Vector3f mBoundingBoxOffset;
	public:
		Mesh();
		~Mesh();
		const Sphere & GetBoundingVolume();
		void InitBoundingBox();
		void SetVertexData(const void*data, int datasize);
		void UpdateVertexPosition(int nIndex, float x, float y, float z, float w = 1.0f);
		void UpdateVertexTexcoord(int nIndex, float x, float y, float z, float w = 1.0f);
		void UpdateVertexNormal(int nIndex, float x, float y, float z, float w = 1.0f);
		void UpdateVertexTangent(int nIndex, float x, float y, float z, float w = 1.0f);
		void UpdateVertexTexcoord1(int nIndex, float x, float y, float z, float w = 1.0f);
		void SetRenderRange(int nStart,int nCount);
		void SetMaterial(Material*mat);
		void AnimateModelMatrix(const void*value);
		void SetVertexCount(int vertexCount);
		void SetIndexCount(int nIndexCount);
		void UpdateIndex(YOSEFUInt16 nIndex, YOSEFUInt16 indice);
		void SetPrimiviteType(GLenum type);
		void Update(float deltaTime);
		void Render(RenderQueue*rq
#if YOSEF_EDITOR
			, DrawCallInfo &rs
#endif
		);
		void RenderShadowMap(RenderQueue*rq
#if YOSEF_EDITOR
			, DrawCallInfo &rs
#endif
		);
		float GetDistanceFromCamera(RenderQueue*rq);
		void SetName(const char*name);
	public:
		DECLEAR_YOSEF_CLASS(Mesh)
	};
}