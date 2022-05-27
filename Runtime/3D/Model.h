#pragma once
#include "Runtime/Base/Component.h"
#include <unordered_map>
#include "Mesh.h"
#include "Runtime/Geometry/AABB.h"
#include "Runtime/Render/YosefGL.h"
#include "Runtime/Serializer/Mesh.serializer.h"
#include "Runtime/Geometry/Geometry.h"

namespace YOSEF {
	class SubModel {
	public:
		SubModel();
		~SubModel();
		EBO	mEBO;
		SmartPtr<Material> mMaterial;
	};
	class Model :public Component {
	public:
		void SetModel(const char*path);
		void SetMaterial(const char*submodelname, Material*mat);
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
	public:
		Model();
		~Model();
		VBO mVBO;
		std::unordered_map<std::string, SubModel*> mSubModels;
	public:
		const Sphere & GetBoundingVolume();
		BoundingVolumeType mBoundingVolumeType;
		bool mbIsBoundingVolumeDirty;
		MinMaxAABB mMinMaxAABB;
		Sphere mLocalBoundingVolume;
		Sphere mBoundingVolume;
		Vector3f mBoundingBoxOffset;
	public:
		DECLEAR_YOSEF_CLASS(Model)
	};
}