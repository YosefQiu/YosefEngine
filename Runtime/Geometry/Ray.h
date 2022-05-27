#pragma once
#include "Runtime/Base/Object.h"
#include "Runtime/Math/Vector3.h"
#include "Point3.h"
namespace YOSEF{
	class Ray : public Object{
	public:
		Vector3f	mOrigin;
		Vector3f	mDirection;
	public:
		Ray() {}
		Ray(const Vector3f& orig, const Vector3f& dir) { mOrigin = orig; SetDirection(dir); }
		Vector3f& GetDirection(){ return mDirection; }

		void SetDirection(const Vector3f& dir) { mDirection = dir; }
		void SetOrigin(const Vector3f& origin) { mOrigin = origin; }
		const Vector3f& GetOrigin()const { return mOrigin; }
		Vector3f GetPoint(float t) const { return mOrigin + t * mDirection; }
		float SqrtDistanceToPoint(const Vector3f &v) const;
	public:
		DECLEAR_YOSEF_CLASS(Ray)
	};
}
