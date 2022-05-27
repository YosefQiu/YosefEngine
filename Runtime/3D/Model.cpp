#include "Model.h"
#include "Runtime/Geometry/Intersection.h"

namespace YOSEF {
	SubModel::SubModel() {
	}

	SubModel::~SubModel() {
	}
	Model::Model() {
		mbIsBoundingVolumeDirty = false;
	}
	Model::~Model() {
		auto iter = mSubModels.begin();
		auto iterEnd = mSubModels.end();
		while (iterEnd!=iter){
			delete iter->second;
			iter++;
		}
	}
	void Model::SetMaterial(const char*submodelname, Material*mat) {
		auto iter = mSubModels.find(submodelname);
		if (iter!=mSubModels.end()){
			iter->second->mMaterial = mat;
		}else{
			Error("Model::SetMaterial fail %s %s",submodelname,mat->mName.mText);
		}
	}
	void Model::SetModel(const char*path) {
		Resource*res = Resource::LoadAssetWithUserPath(path);//load a compressed resource
		if (res != nullptr) {
			
		}
		else {
			Error("set model data fail %s", path);
		}
	}
	const Sphere&Model::GetBoundingVolume() {
		if (mbIsBoundingVolumeDirty) {
			mbIsBoundingVolumeDirty = false;
		}
		return mBoundingVolume;
	}
	void Model::Update(float deltaTime) {
		if (mVBO.mSize==0){
			return;
		}
		if (mbPositionChanged) {
			mbIsBoundingVolumeDirty = true;
			mbPositionChanged = false;
		}
	}

	void Model::Render(RenderQueue*rq
#if YOSEF_EDITOR
		, DrawCallInfo &rs
#endif
	) {
		if (mVBO.mSize==0){
			return;
		}
		float distance_from_camera = GetDistanceFromCamera(rq);
		if (distance_from_camera < 0.0f) {
			return;
		}
	}
	void Model::RenderShadowMap(RenderQueue*rq
#if YOSEF_EDITOR
		, DrawCallInfo &rs
#endif
	) {
		if (mVBO.mSize == 0) {
			return;
		}
	}
	float Model::GetDistanceFromCamera(RenderQueue*rq) {
		GetBoundingVolume();
		return 0.0f;
	}
}
