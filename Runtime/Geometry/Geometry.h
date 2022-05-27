#pragma once
#include "AABB.h"
#include "Sphere.h"
namespace YOSEF {
	enum BoundingVolumeType{
		kBoundingVolumeTypeNone,
		kBoundingVolumeTypeAABB,
		kBoundingVolumeTypeSphere,
		kBoundingVolumeTypeCapsule,
		kBoundingVolumeTypeCount
	};
}