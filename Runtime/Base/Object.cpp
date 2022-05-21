#include "Object.h"
namespace YOSEF 
{
	Object::Object(int autorelease) :mReferenceCount(0),mObjectMask(autorelease) 
	{}

	Object::~Object() { }

	void Object::retain() 
	{
		mReferenceCount++;
	}

	void Object::release() 
	{
		mReferenceCount--;
		if (mReferenceCount == 0) 
		{
			if (mObjectMask == 1) 
			{
				delete this;
			}
		}
	}
}