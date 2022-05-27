#pragma once
#include "Runtime/Math/Vector3.h"
namespace YOSEF{
	class Plane{
	public:
		Vector3f normal;
		float distance;
		const float& a()const { return normal.x; }
		const float& b()const { return normal.y; }
		const float& c()const { return normal.z; }
		const float& d() const { return distance; }
		float& d() { return distance; }
		const Vector3f& GetNormal()const { return normal; }
		Plane() { }
		Plane(float a, float b, float c, float d) { normal.x = a; normal.y = b; normal.z = c; distance = d; }
		Plane& operator *= (float scale);
		bool operator == (const Plane& p) { return normal == p.normal && distance == p.distance; }
		bool operator != (const Plane& p) { return normal != p.normal || distance != p.distance; }
		void SetInvalid() { normal = Vector3f(0, 0, 0); distance = 0.0F; }

		void SetNormalAndPosition(const Vector3f& inNormal, const Vector3f& inPoint);
		float GetDistanceToPoint(const Vector3f& inPt) const;
		bool GetSide(const Vector3f& inPt) const;
	};
	inline float Plane::GetDistanceToPoint(const Vector3f& inPt)const{
		return Dot(normal, inPt) + distance;
	}

	inline bool Plane::GetSide(const Vector3f& inPt) const
	{
		return Dot(normal, inPt) + distance > 0.0F;
	}

	inline void Plane::SetNormalAndPosition(const Vector3f& inNormal, const Vector3f& inPoint)
	{
		normal = inNormal;
		distance = -Dot(inNormal, inPoint);
	}
	inline Plane& Plane::operator *= (float scale)
	{
		normal *= scale;
		distance *= scale;
		return *this;
	}
}
